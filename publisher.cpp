#include <ros/ros.h>
#include <std_msgs/String.h>

/*
 * Based on https://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber
 *
 * Student: Bruna C Russi
 */

int main(int argc, char **argv)
{
    ros::init(argc, argv, "publisher_node");
    ros::NodeHandle nh;

    ros::Publisher publisher = nh.advertise<std_msgs::String>("my_str", 10);
    ros::Rate rate(1);

    while (ros::ok())
    {
        std_msgs::String message;
        message.data = "First practice with ROS";
        publisher.publish(message);
        ROS_INFO("Published String: %s", message.data.c_str());

        rate.sleep();
    }

    return 0;
}