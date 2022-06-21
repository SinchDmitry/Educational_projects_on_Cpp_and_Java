#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char **argv)
{
	ros::init(argc, argv, "circle_move");
	ros::NodeHandle n;
	ros::Publisher vel_pub = n.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);
	geometry_msgs::Twist	vel;
	ros::Rate loop_rate(10);
	while (ros::ok())
	{
		vel.linear.x = 0.4;
		vel.angular.z = 1.57;
		vel_pub.publish(vel);
		loop_rate.sleep();
	}
	return (0);
}
