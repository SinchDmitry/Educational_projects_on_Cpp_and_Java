cmake_minimum_required(VERSION 3.0.2)
project(opencv_togray)

  
find_package(catkin REQUIRED COMPONENTS
  sensor_msgs
  cv_bridge 
  roscpp 
  std_msgs 
  image_transport
)

catkin_package(
)
 
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)


add_executable(printer src/image_publisher.cpp)
target_link_libraries(printer ${catkin_LIBRARIES})

add_executable(to_grey src/grey_picture.cpp)
target_link_libraries(to_grey ${catkin_LIBRARIES})
