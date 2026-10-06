#include "pc_init.hpp"
#include "types.hpp"
#include "utils.hpp"
#include <nlohmann/json.hpp>
#include <rtc/rtc.hpp>

using json = nlohmann::json;

void handleSendIce(const json &msg, const std::shared_ptr<User> &connectedUser,
                   std::map<std::string, Room> &rooms) {

  std::string candidate = msg["ice-candidate"]["candidate"];
  std::string sdpMid = msg["ice-candidate"]["sdpMid"];
  connectedUser->connections.pc->addRemoteCandidate(
      rtc::Candidate(candidate, sdpMid));
}

void handleJoinVoiceMessage(const json &msg,
                            const std::shared_ptr<User> &connectedUser,
                            std::map<std::string, Room> &rooms) {
  std::string sdp = msg["offer"]["sdp"];
  std::string type = msg["offer"]["type"];

  std::shared_ptr<rtc::PeerConnection> initializedPc =
      pcInit(connectedUser, rooms);
  connectedUser->connections.pc = initializedPc;

  connectedUser->connections.pc->setRemoteDescription(
      rtc::Description(sdp, type));
}

void handleChatSentMessage(const json &msg,
                           const std::shared_ptr<User> &connectedUser,
                           std::map<std::string, Room> &rooms) {
  // TODO verify the user is in the room they're sending a message to
  std::string roomId = msg["roomId"];
  std::string username = msg["username"];
  std::string chat = msg["chat"];
  if (rooms.contains(roomId)) {
    Room &room = rooms[roomId];

    json chatMessage = {{"type", "chat_received"},
                        {"roomId", roomId},
                        {"username", username},
                        {"chat", chat}};

    std::string jsonDump = chatMessage.dump();
    for (const std::shared_ptr<User> &user : room.users) {
      user->connections.userWs->send(jsonDump);
    }
  }
}

void handleJoinRoomMessage(const json &msg,
                           const std::shared_ptr<User> &connectedUser,
                           std::map<std::string, Room> &rooms) {
  // TODO check if user is already in a room. if so remove from room
  // list
  // TODO validate the different types of websocket message have the
  // right JSON payload
  // TODO make sure username isn't already used in room
  std::string roomId = msg["roomId"];
  std::string username = msg["username"];

  connectedUser->username = username;
  // std::map::operator[] automatically returns a new Room object if one
  // doesn't exist already
  Room &room = rooms[roomId];
  room.id = roomId;

  connectedUser->roomId = roomId;
  room.users.push_back(connectedUser);

  updateRoomUsersStatusMessage(room);
}

void handleLeaveVoiceMessage(const json &msg,
                             const std::shared_ptr<User> &connectedUser,
                             std::map<std::string, Room> &rooms) {

  if (connectedUser->connections.pc) {
    connectedUser->connections.pc->close();
    connectedUser->connections.pc.reset();
  }

  if (connectedUser->connections.audioTrack) {
    connectedUser->connections.audioTrack->close();
    connectedUser->connections.audioTrack.reset();
  }
}
