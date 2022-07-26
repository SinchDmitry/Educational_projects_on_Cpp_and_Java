cmake_minimum_required(VERSION 3.0.2)
project(opencvid)

  
find_package(catkin REQUIRED COMPONENTS
  sensor_msgs
  cv_bridge 
  roscpp 
  std_msgs 
  image_transport
  dynamic_reconfigure
  # aruco_ros
  tf
)

find_package(OpenCV REQUIRED)
  

# generate_dynamic_reconfigure_options(
  # cfg/CannyDetection.cfg
  #...
# )
 
catkin_package(
  
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

# add_executable(printer src/image_publisher.cpp)
# target_link_libraries(printer ${catkin_LIBRARIES})

add_executable(cor src/grey_picture.cpp)
# add_dependencies(cor ${PROJECT_NAME}_gencfg)
target_link_libraries(cor ${catkin_LIBRARIES} ${OpenCV_LIBRARIES} )
