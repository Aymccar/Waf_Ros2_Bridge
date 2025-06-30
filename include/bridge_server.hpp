#pragma once
#include "bridge_node.hpp"
#include <rclcpp/rclcpp.hpp>

class BridgeServer {
    public: 
        static void init();
        static void spin(BridgeNode node){rclcpp::spin(node.get());};
};
