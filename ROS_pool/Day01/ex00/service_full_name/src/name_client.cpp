#include "ros/ros.h"
#include "service_full_name/summ_full_name.h"
#include <cstdlib>
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "name_client");
  if (argc != 4)
  {
    ROS_INFO("usage: full_name_sum X Y Z");
    return 1;
  }
  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<service_full_name::summ_full_name>("sum_full_name");
  service_full_name::summ_full_name srv;
  srv.request.first_name = argv[1];
  srv.request.last_name = argv[2];
  srv.request.patronymic = argv[3];
  if (client.call(srv))
  {
    ROS_INFO("Full name: %s", srv.response.full_name.c_str());
  }
  else
  {
    ROS_ERROR("Failed to call service_full_name");
    return 1;
  }
  return 0;
}
