#include <ros/ros.h>
#include <math.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/PointCloud2.h>

static double move_speed = 0;
static double target_dist = 0.6;
static double k = 0.1;
ros::Publisher pub;

void	distance_check(const sensor_msgs::PointCloud2::ConstPtr& dist)
{
	float	*x;
	float	*y;
	float	*z;
	float	distance;
	float	min_dist = 30.0;

	for (int a = 0; a < dist->data.size(); a += dist->point_step) {
		x = (float *)&dist->data[a];
		y = (float *)&dist->data[a + 4];
		z = (float *)&dist->data[a + 8];

		// ROS_INFO("%f // %f // %f", *x, *y, *z);
		if (*y > 0.0 || std::isnan(*x) || std::isnan(*y) || std::isnan(*z))	continue ;
		distance = sqrt(pow(*x, 2.0) + pow(*y, 2.0) + pow(*z, 2.0));
		if (distance < min_dist) 	min_dist = distance;
	}
	// ROS_INFO("%f", min_dist);
	move_speed = (min_dist - target_dist) * k;
	if (move_speed > 0.4) move_speed = 0.4;
	geometry_msgs::Twist vel;
	vel.linear.x = move_speed;
	pub.publish(vel);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "regulator");
    ros::NodeHandle n;
	pub = n.advertise<geometry_msgs::Twist>("/cmd_vel", 10);
	ros::Subscriber vel_data = n.subscribe("/camera/depth/points", 1000, distance_check);
	ros::spin();

    return 0;
}