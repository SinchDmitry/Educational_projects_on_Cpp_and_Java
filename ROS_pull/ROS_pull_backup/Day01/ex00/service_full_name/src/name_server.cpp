#include "ros/ros.h"
#include "service_full_name/summ_full_name.h"
#include "std_msgs/String.h"

bool add(service_full_name::summ_full_name::Request  &req, \
	service_full_name::summ_full_name::Response &res)
{
  res.full_name = req.first_name + req.last_name + req.patronymic;
  ROS_INFO("request: x=%s, y=%s, z=%s", req.first_name.c_str(), req.last_name.c_str(), \
  	req.patronymic.c_str());
  ROS_INFO("sending back response: [%s]", res.full_name.c_str());
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "service_name");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("sum_full_name", add);
  ROS_INFO("Ready to return full name.");
  ros::spin();

  return 0;
}