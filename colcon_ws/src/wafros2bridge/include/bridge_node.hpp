#pragma once
#include "bridge_publisher.hpp"
#include "bridge_publisher_string.hpp"
#include "bridge_publisher_array.hpp"
#include "bridge_subscriber_array.hpp"
#include "bridge_subscriber_IMU.hpp"

#include <rclcpp/rclcpp.hpp>
#include <string>
#include <vector>
#include <functional>


class BridgeNode {
public :
    //Construtctor
    BridgeNode(std::string name);

    //Publisher
    //TODO Templatization
    BridgePublisherString* create_publisher_string(std::string name, int i);
    BridgePublisherArray* create_publisher_array(std::string name, int i);

    //Subscriber
    //TODO Templatization
    BridgeSubscriberArray* create_subscriber_array(std::string name, int i, std::function<void(array_msg_t)> callback);
    BridgeSubscriberIMU* create_subscriber_IMU(std::string name, int i, std::function<void(IMU_msg_t)> callback);

    //Spin
    void spin();
    void spin_some();

    //Get node (TODO delete)
    rclcpp::Node::SharedPtr get(){return node;};

private :
    rclcpp::Node::SharedPtr node;
};
