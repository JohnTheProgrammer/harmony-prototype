#include "types.hpp"
#include <memory>
#include <nlohmann/json.hpp>
#include <rtc/rtc.hpp>

std::shared_ptr<rtc::PeerConnection>
pcInit(const std::shared_ptr<User> &connectedUser,
       std::map<std::string, Room> &rooms);
