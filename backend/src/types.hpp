#pragma once
#include <memory>
#include <rtc/rtc.hpp>

struct Connections {
  std::shared_ptr<rtc::WebSocket> userWs;
  std::shared_ptr<rtc::PeerConnection> pc;
  std::shared_ptr<rtc::Track> audioTrack;
};

struct User {
  std::string id;
  std::string address;
  std::string username;
  std::string roomId;
  Connections connections;
};

struct Room {
  std::string id;
  std::vector<std::shared_ptr<User>> users;
};
