#pragma once
#include "bridge_publisher.hpp"
#include "bridge_publisher_string.hpp"

#include <rclcpp/rclcpp.hpp>
#include <string>
#include <vector>


class BridgeNode {
public :
    BridgeNode(std::string name);

    //TODO Templatization
    BridgePublisherString* create_publisher_string(std::string name, int i);
    rclcpp::Node::SharedPtr get(){return node;};

private :
    rclcpp::Node::SharedPtr node;
};
