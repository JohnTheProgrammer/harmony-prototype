#include "types.hpp"
#include <nlohmann/json.hpp>

void wsRouter(const nlohmann::json &msg,
              const std::shared_ptr<User> &connectedUser,
              std::map<std::string, Room> &rooms);
