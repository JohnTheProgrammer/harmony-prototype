#include "types.hpp"
#include <nlohmann/json.hpp>
#include <string>
#include <uuid.h>

using json = nlohmann::json;

json userConnectionJson(const std::shared_ptr<User> &user) {
  json connectionsMap = {{
                             "audio",
                             false,
                         },
                         {"video", false},
                         {"screenShare", false}};
  if (user->connections.audioTrack && user->connections.audioTrack->isOpen()) {
    connectionsMap["audio"] = true;
  }

  return {{"username", user->username},
          {"id", user->id},
          {"connections", connectionsMap}};
}

void sendRoomWsMessage(const Room &room, const json jsonData) {
  std::string jsonDump = jsonData.dump();
  for (const std::shared_ptr<User> &user : room.users) {
    user->connections.userWs->send(jsonDump);
  }
}

void updateRoomUsersStatusMessage(const Room &room) {
  json usersMap;
  for (const std::shared_ptr<User> &user : room.users) {
    usersMap[user->id] = userConnectionJson(user);
  }

  json roomUpdateMessage = {
      {"type", "room_update"},
      {"roomId", room.id},
      {"users", usersMap},
  };

  sendRoomWsMessage(room, roomUpdateMessage);
}

namespace harmony {
namespace uuid {
namespace {
std::mt19937 engine;
std::unique_ptr<uuids::uuid_random_generator> gen;
} // namespace

void init() {
  std::random_device rd;
  std::array<int, std::mt19937::state_size> seed_data;
  std::generate(seed_data.begin(), seed_data.end(), std::ref(rd));
  std::seed_seq seq{seed_data.begin(), seed_data.end()};

  engine.seed(seq);
  gen = std::make_unique<uuids::uuid_random_generator>(engine);
}

std::string genStringUuid() { return uuids::to_string((*gen)()); }
} // namespace uuid
} // namespace harmony
