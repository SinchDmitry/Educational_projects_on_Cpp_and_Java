#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/LaserScan.h>

static double move_speed = 0;
static double target_dist = 0.6;
static double k = 0.7;
ros::Publisher pub;

void	distance_check(const sensor_msgs::LaserScan::ConstPtr& dist)
{
	int min_dist = dist->range_max;
	for (int i = 0; i < dist->ranges.size(); i++)
		if (dist->ranges[i] < min_dist && dist->ranges[i] != \
			std::numeric_limits<float>::infinity() && dist->ranges[i] != \
			-std::numeric_limits<float>::infinity())	min_dist = dist->ranges[i];
	move_speed = (min_dist - target_dist) * k;
	if (move_speed > 0.5) move_speed = 0.5;
	geometry_msgs::Twist vel;
	vel.linear.x = move_speed;
	pub.publish(vel);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "regulator");
    ros::NodeHandle n;
	pub = n.advertise<geometry_msgs::Twist>("/cmd_vel", 10);
	ros::Subscriber vel_data = n.subscribe("/rrbot/laser/scan", 1000, distance_check);
	ros::spin();

    return 0;
}