#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "std_msgs/String.h"
// #include <sstream>

std::string data;

void	twist_compare(std::string msg, ros::Publisher &pub)
{
	if (!msg.compare("move_forward") || !msg.compare("move_backward") \
		|| !msg.compare("turn_left") || !msg.compare("turn_right")) {
		geometry_msgs::Twist	vel;
		if (!msg.compare("move_forward"))
			vel.linear.x = 1;
		else if (!msg.compare("move_backward"))
			vel.linear.x = -1;
		else if (!msg.compare("turn_left"))
			vel.angular.z = 1.5;
		else if (!msg.compare("turn_right"))
			vel.angular.z = -1.5;
		pub.publish(vel);
	}
}

void	msg_check(const std_msgs::String::ConstPtr& msg)
{
	data = msg->data.c_str();
	ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "text_to_cmd_vel");
	ros::NodeHandle n;
	ros::Subscriber vel_data = n.subscribe("turtle1/cmd_text", 1000, msg_check);
	ros::Publisher vel_pub = n.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000);
	ros::Rate loop_rate(1);
	while (ros::ok())
	{
		loop_rate.sleep();
		ros::spinOnce();
		twist_compare(data, vel_pub);
		data.clear();
	}
	return (0);
}
