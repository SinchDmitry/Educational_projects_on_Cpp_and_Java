cmake_minimum_required(VERSION 3.0.2)
project(service_full_name)

  
find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  rostime
  rospy
  std_msgs
  genmsg
  message_generation
)
  
add_message_files(
	FILES
	full_name_message.msg
  )

## Generate services in the 'srv' folder
add_service_files(
   FILES
   summ_full_name.srv
 )

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(

CATKIN_DEPENDS message_runtime
)

include_directories(
include
  ${catkin_INCLUDE_DIRS}
)

add_executable(name_service src/name_server.cpp)
target_link_libraries(name_service ${catkin_LIBRARIES})
add_dependencies(name_service service_full_name_generate_messages_cpp)

add_executable(name_client src/name_client.cpp)
target_link_libraries(name_client ${catkin_LIBRARIES})
add_dependencies(name_client service_full_name_generate_messages_cpp)