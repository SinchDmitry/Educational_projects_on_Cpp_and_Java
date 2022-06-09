#include <ros/ros.h>
#include <tf2_ros/transform_broadcaster.h>
#include <tf2/LinearMath/Quaternion.h>

int main(int argc, char** argv){
  	ros::init(argc, argv, "my_tf2_broadcaster");
  	ros::NodeHandle	node;

	tf2_ros::TransformBroadcaster tfb;
  	geometry_msgs::TransformStamped transformStamped;

	// radius = atof(argv[1]);
	double radius = 0;
	int direction = 0;
	ros::param::get("/radius", radius);
	ros::param::get("/direction_of_rotation", direction);
	if (radius < 0){
		ROS_ERROR("Your radius must be positive");
    	return -1;
	}
	// direction = atoi(argv[2]);
	if (direction != 1 && direction != -1){
		ROS_ERROR("Direction must be 1 or -1, your value = %d", direction);
    	return -1;
	}
  transformStamped.header.frame_id = "turtle1";
  transformStamped.child_frame_id = "carrot1";
  transformStamped.transform.translation.x = 0.0;
  transformStamped.transform.translation.y = radius;
  transformStamped.transform.translation.z = 0.0;
  tf2::Quaternion q;
        q.setRPY(0, 0, 0);
  transformStamped.transform.rotation.x = q.x();
  transformStamped.transform.rotation.y = q.y();
  transformStamped.transform.rotation.z = q.z();
  transformStamped.transform.rotation.w = q.w();

  ros::Rate rate(10.0);
  while (node.ok()){
    transformStamped.header.stamp = ros::Time::now();
	if (direction == 1){
		transformStamped.transform.translation.x = radius * sin(ros::Time::now().toSec());
    	transformStamped.transform.translation.y = radius * cos(ros::Time::now().toSec());
	}
	else{
		transformStamped.transform.translation.y = radius * sin(ros::Time::now().toSec());
    	transformStamped.transform.translation.x = radius * cos(ros::Time::now().toSec());
	}
    tfb.sendTransform(transformStamped);
    rate.sleep();
    printf("sending\n");
  }

};