#pragma once
#include "bridge_publisher.hpp"

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <string>

using Publisher_string_t = rclcpp::Publisher<std_msgs::msg::String>::SharedPtr;

class BridgePublisherString : public BridgePublisher{
public:
    BridgePublisherString(Publisher_string_t publisher);
    //TODO IMPLEMENT A DESTRUCTOR
    void publish(std::string msg);

private:
    Publisher_string_t publisher_;
};
