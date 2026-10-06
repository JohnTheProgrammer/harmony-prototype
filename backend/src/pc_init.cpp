#include "rtc/peerconnection.hpp"
#include "types.hpp"
#include "utils.hpp"
#include <memory>
#include <nlohmann/json.hpp>
#include <rtc/rtc.hpp>

using json = nlohmann::json;

std::shared_ptr<rtc::PeerConnection>
pcInit(const std::shared_ptr<User> &connectedUser,
       std::map<std::string, Room> &rooms) {
  auto pc = std::make_shared<rtc::PeerConnection>();
  std::weak_ptr<User> weakUser = connectedUser;

  pc->onLocalDescription([weakUser](rtc::Description sdp) {
    auto user = weakUser.lock();
    if (user) {
      json peerConnectionAnswer = {{"type", "answer"},
                                   {"answer", std::string(sdp)}};
      user->connections.userWs->send(peerConnectionAnswer.dump());
    }
  });

  pc->onLocalCandidate([weakUser](rtc::Candidate candidate) {
    auto user = weakUser.lock();
    if (user) {
      json peerConnectionAnswer = {{"type", "receive_ice"},
                                   {"iceCandidate",
                                    {{"candidate", std::string(candidate)},
                                     {"sdpMid", candidate.mid()}}}};
      user->connections.userWs->send(peerConnectionAnswer.dump());
    }
  });

  pc->onStateChange([weakUser](rtc::PeerConnection::State state) {
    std::cout << "New State " << state << std::endl;
  });

  pc->onTrack([weakUser, &rooms](std::shared_ptr<rtc::Track> track) {
    auto user = weakUser.lock();
    if (user) {
      if (track->description().type() == "audio") {

        rtc::Description::Audio audio(track->mid(),
                                      rtc::Description::Direction::SendRecv);
        audio.addOpusCodec(111);
        track->setDescription(audio);

        // what is message_variant, rtpPacket, and what is this hold_alternative
        // conditional?
        track->onMessage([weakUser, &rooms](rtc::message_variant data) {
          auto user = weakUser.lock();
          if (user && std::holds_alternative<rtc::binary>(data)) {
            // If they haven't joined a room yet, just drop the packet
            if (user->roomId.empty())
              return;

            auto rtpPacket = std::get<rtc::binary>(data);
            auto &room = rooms[user->roomId];

            for (const std::shared_ptr<User> &roomUser : room.users) {
              if (roomUser != user && roomUser->connections.audioTrack &&
                  roomUser->connections.audioTrack->isOpen()) {
                roomUser->connections.audioTrack->send(rtpPacket);
              }
            }
          }
        });

        user->connections.audioTrack = track;
      }

      track->onOpen([weakUser, &rooms]() {
        auto user = weakUser.lock();
        if (user) {
          json userUpdate = {{"type", "user_update"},
                             {"roomId", rooms[user->roomId].id},
                             {"user", userConnectionJson(user)}};

          sendRoomWsMessage(rooms[user->roomId], userUpdate);
        }
      });

      track->onClosed([weakUser, &rooms]() {
        auto user = weakUser.lock();
        if (user) {
          json userUpdate = {{"type", "user_update"},
                             {"roomId", rooms[user->roomId].id},
                             {"user", userConnectionJson(user)}};

          sendRoomWsMessage(rooms[user->roomId], userUpdate);
        }
      });
    }
  });

  return pc;
}
