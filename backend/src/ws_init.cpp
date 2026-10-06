#include "types.hpp"
#include "utils.hpp"
#include "ws_router.hpp"
#include <iostream>
#include <memory>
#include <nlohmann/json.hpp>
#include <ostream>
#include <rtc/rtc.hpp>
#include <string>
#include <uuid.h>

using json = nlohmann::json;
using MessageHandler = std::function<void(const json &, std::shared_ptr<User> &,
                                          std::map<std::string, Room> &)>;

void wsInit(std::shared_ptr<rtc::WebSocket> ws,
            std::map<std::string, Room> &rooms) {
  auto connectedUser = std::make_shared<User>();

  connectedUser->id = harmony::uuid::genStringUuid();
  connectedUser->address = ws->remoteAddress().value_or("unknown");
  connectedUser->connections = Connections();
  connectedUser->connections.userWs = ws;

  ws->onMessage([connectedUser, &rooms](rtc::message_variant data) {
    if (std::holds_alternative<std::string>(data)) {
      json msg = json::parse(std::get<std::string>(data));
      wsRouter(msg, connectedUser, rooms);
    }
  });

  ws->onClosed([connectedUser, &rooms]() {
    if (rooms.contains(connectedUser->roomId)) {
      Room &room = rooms[connectedUser->roomId];

      std::erase_if(room.users,
                    [&connectedUser](const std::shared_ptr<User> &user) {
                      return user->username == connectedUser->username;
                    });

      updateRoomUsersStatusMessage(room);

      if (room.users.empty()) {
        rooms.erase(connectedUser->roomId);
        std::cout << "Room" << connectedUser->roomId << "deleted (empty)."
                  << std::endl;
      }
    }
  });
}
