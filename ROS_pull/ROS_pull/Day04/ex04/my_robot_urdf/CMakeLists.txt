cmake_minimum_required(VERSION 3.0.2)
project(my_robot_urdf)

  
find_package(catkin REQUIRED COMPONENTS
  joint_state_publisher
  joint_state_publisher_gui
  robot_state_publisher
  roscpp
  rospy
  rviz
  xacro
)

catkin_package( 
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)
 
install(FILES
  robot_depth_camera.launch
#   # myfile1
#   # myfile2
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

add_executable(dist_control src/distance_regulator.cpp)
target_link_libraries(dist_control ${catkin_LIBRARIES})
