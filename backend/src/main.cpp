#include "types.hpp"
#include "utils.hpp"
#include "ws_init.hpp"
#include <iostream>
#include <memory>
#include <nlohmann/json.hpp>
#include <rtc/rtc.hpp>
#include <string>

using json = nlohmann::json;

void handleWebRTCPeerConnection() {}

int main() {
  harmony::uuid::init();

  rtc::InitLogger(rtc::LogLevel::Info);
  std::map<std::string, Room> rooms;

  rtc::WebSocketServer::Configuration config;
  config.bindAddress = "localhost";
  config.port = 8081;

  auto wsServer = std::make_shared<rtc::WebSocketServer>(config);

  wsServer->onClient(
      [&rooms](std::shared_ptr<rtc::WebSocket> ws) { wsInit(ws, rooms); });

  std::cout << "Harmony Signaling Server running on port 8081..." << std::endl;

  // Keep the main thread alive TODO replace this with mutex/C++ threading stuff
  std::string input;
  std::getline(std::cin, input);

  return 0;
}
