
cmake_minimum_required(VERSION 3.0.2)
project(archibald)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  rostime
  std_msgs
  genmsg
)

 add_message_files(
   FILES
   cmd_text.msg
#   Message2.msg
 )

generate_messages(
   DEPENDENCIES
   std_msgs
 )
  
catkin_package(
  
)

  
include_directories(
 include
  ${catkin_INCLUDE_DIRS}
)


add_executable(text_to_cmd_vel src/text_to_cmd_vel.cpp)
target_link_libraries(text_to_cmd_vel ${catkin_LIBRARIES})
add_dependencies(text_to_cmd_vel archibald_generate_messages_cpp)

add_executable(listener src/listener.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})
add_dependencies(listener archibald_generate_messages_cpp)
