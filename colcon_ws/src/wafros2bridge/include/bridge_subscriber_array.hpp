#pragma once
#include "bridge_subscriber.hpp"

#include <vector>
#include <functional>

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32_multi_array.hpp>

using Subscriber_int_array_t = rclcpp::Subscription<std_msgs::msg::Int32MultiArray>::SharedPtr;
struct array_msg_t {
    std::vector<int> data;
};

class BridgeSubscriberArray : public BridgeSubscriber {
public:
    BridgeSubscriberArray(std::function<void(array_msg_t)> callback);
    //TODO Destructor

    void set_subscriber(Subscriber_int_array_t subscriber){subscriber_ = subscriber;};

    void callback(std_msgs::msg::Int32MultiArray::SharedPtr msg);
    array_msg_t get() const {return data;};

private:
    Subscriber_int_array_t subscriber_;

    array_msg_t data;
    std::function<void(array_msg_t)> user_callback;
};
