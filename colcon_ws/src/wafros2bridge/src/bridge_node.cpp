//Include files include the message definition
#include "bridge_node.hpp"
#include "bridge_publisher_string.hpp"
#include "bridge_publisher_array.hpp"
#include "bridge_subscriber_array.hpp"
#include "bridge_subscriber_IMU.hpp"

#include <string>
#include <functional>

using std::placeholders::_1;

BridgeNode::BridgeNode(std::string name){
    node = std::make_shared<rclcpp::Node>(name);
}

void BridgeNode::spin(){
    rclcpp::spin(node);
}

void BridgeNode::spin_some(){
    rclcpp::spin_some(node);
}

BridgePublisherString* BridgeNode::create_publisher_string(std::string name, int i){
       
       auto publisher = node->create_publisher<std_msgs::msg::String>(name, i);
       return new BridgePublisherString(publisher);
}

BridgePublisherArray* BridgeNode::create_publisher_array(std::string name, int i){
       
       auto publisher = node->create_publisher<std_msgs::msg::Int32MultiArray>(name, i);
       return new BridgePublisherArray(publisher);
}

BridgeSubscriberArray* BridgeNode::create_subscriber_array(std::string name, int i, std::function<void(array_msg_t)> callback){

    auto* bridge_sub = new BridgeSubscriberArray(callback);

    auto subscriber = node->create_subscription<std_msgs::msg::Int32MultiArray>(name, i, std::bind(&BridgeSubscriberArray::callback, bridge_sub, _1));
    bridge_sub->set_subscriber(subscriber);
    return bridge_sub;
}

BridgeSubscriberIMU* BridgeNode::create_subscriber_IMU(std::string name, int i, std::function<void(IMU_msg_t)> callback){

    auto* bridge_sub = new BridgeSubscriberIMU(callback);

    auto subscriber = node->create_subscription<sensor_msgs::msg::Imu>(name, i, std::bind(&BridgeSubscriberIMU::callback, bridge_sub, _1));
    bridge_sub->set_subscriber(subscriber);
    return bridge_sub;
}
