#include <ros/ros.h>
#include <std_msgs/String.h>

/*
 *  Based on https://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber
 *
 * Student Bruna C Russi
 */

void topicCallback(const std_msgs::String::ConstPtr &msg)
{
    ROS_INFO("Received String: %s", msg->data.c_str());
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "subscriber_node");
    ros::NodeHandle nh;

    ros::Subscriber subscriber = nh.subscribe("my_str", 10, topicCallback);

    ros::spin();

    return 0;
}