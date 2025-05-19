#include "bridge_server.hpp"

void BridgeServer::init(){
    int argc = 0;
    char** argv = nullptr;
    rclcpp::init(argc, argv);
}
