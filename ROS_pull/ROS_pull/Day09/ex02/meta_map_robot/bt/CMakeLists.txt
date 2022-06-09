cmake_minimum_required(VERSION 3.0.2)
project(bt)

  
find_package(catkin REQUIRED COMPONENTS
  behaviortree_cpp_v3
  roscpp
  std_msgs
  move_base_msgs
  actionlib
)

  
catkin_package(
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(tree src/LearnBasics.cpp)
target_link_libraries(tree ${catkin_LIBRARIES})
