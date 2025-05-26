#pragma once
#include "bridge_subscriber.hpp"

#include <vector>
#include <functional>

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32_multi_array.hpp>

using Subscriber_int_array_t = rclcpp::Subscription<std_msgs::msg::Int32MultiArray>::SharedPtr;

class BridgeSubscriberArray : public BridgeSubscriber {
public:
    BridgeSubscriberArray(std::function<void(std::vector<int>)> callback);
    //TODO Destructor

    void set_subscriber(Subscriber_int_array_t subscriber){subscriber_ = subscriber;};

    void callback(std_msgs::msg::Int32MultiArray::SharedPtr msg);
    std::vector<int> get() const {return data;};

private:
    Subscriber_int_array_t subscriber_;

    std::vector<int> data;
    std::function<void(std::vector<int>)> user_callback;
};
