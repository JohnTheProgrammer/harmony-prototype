#include "types.hpp"
#include "ws_handlers.hpp"
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using MessageHandler =
    std::function<void(const json &, const std::shared_ptr<User> &,
                       std::map<std::string, Room> &)>;

std::unordered_map<std::string, MessageHandler> routes = {
    {"join_room", handleJoinRoomMessage},
    {"chat_sent", handleChatSentMessage},
    {"join_voice", handleJoinVoiceMessage},
    {"send_ice", handleSendIce},
    {"leave_voice", handleLeaveVoiceMessage}};

void wsRouter(const json &msg, const std::shared_ptr<User> &connectedUser,
              std::map<std::string, Room> &rooms) {
  std::cout << "Received message: " << msg.dump() << std::endl;
  if (!msg.contains("type")) {
    std::cout << "Received message without type key" << std::endl;
    return;
  }

  if (!routes.contains(msg["type"])) {
    std::cout << "Received message for type that isn't handled" << std::endl;
    return;
  }

  std::string key = msg["type"];

  routes[key](msg, connectedUser, rooms);
}
