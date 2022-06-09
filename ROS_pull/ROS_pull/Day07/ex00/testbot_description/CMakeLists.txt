cmake_minimum_required(VERSION 3.0.2)
project(testbot_description)
 
find_package(catkin REQUIRED COMPONENTS
  urdf
)

catkin_package(
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)
