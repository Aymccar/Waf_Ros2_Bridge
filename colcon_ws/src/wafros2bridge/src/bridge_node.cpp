#include "bridge_node.hpp"
#include "bridge_publisher_string.hpp"

#include <string>

BridgeNode::BridgeNode(std::string name){
    node = std::make_shared<rclcpp::Node>(name);
}

BridgePublisherString* BridgeNode::create_publisher_string(std::string name, int i){
       
       auto publisher = node->create_publisher<std_msgs::msg::String>(name, i);

       return new BridgePublisherString(publisher);
}

