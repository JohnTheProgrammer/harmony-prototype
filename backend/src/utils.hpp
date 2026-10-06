#include "types.hpp"
#include <nlohmann/json.hpp>
using json = nlohmann::json;

std::string deriveUserStatus(const std::shared_ptr<User> &user);

void updateRoomUsers(const Room &room, const json jsonData);

void updateRoomUsersStatusMessage(const Room &room);

namespace harmony {
namespace uuid {
void init();

std::string genStringUuid();
} // namespace uuid
} // namespace harmony

void sendRoomWsMessage(const Room &room, const json jsonData);

json userConnectionJson(const std::shared_ptr<User> &user);
