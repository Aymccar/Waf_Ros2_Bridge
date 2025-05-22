#pragma once
#include "bridge_publisher.hpp"

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32_multi_array.hpp>
#include <string>

using Publisher_int_array_t = rclcpp::Publisher<std_msgs::msg::Int32MultiArray>::SharedPtr;

class BridgePublisherArray : public BridgePublisher{
public:
    BridgePublisherArray(Publisher_int_array_t publisher);
    //TODO IMPLEMENT A DESTRUCTOR
    void publish(uint16_t* data, size_t n);

private:
    Publisher_int_array_t publisher_;
};
