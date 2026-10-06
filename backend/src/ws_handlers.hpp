#include "types.hpp"
#include <nlohmann/json.hpp>
using json = nlohmann::json;

void handleSendIce(const json &msg, const std::shared_ptr<User> &connectedUser,
                   std::map<std::string, Room> &rooms);

void handleJoinVoiceMessage(const json &msg,
                            const std::shared_ptr<User> &connectedUser,
                            std::map<std::string, Room> &rooms);

void handleChatSentMessage(const json &msg,
                           const std::shared_ptr<User> &connectedUser,
                           std::map<std::string, Room> &rooms);

void handleJoinRoomMessage(const json &msg,
                           const std::shared_ptr<User> &connectedUser,
                           std::map<std::string, Room> &rooms);
void handleLeaveVoiceMessage(const json &msg,
                             const std::shared_ptr<User> &connectedUser,
                             std::map<std::string, Room> &rooms);
