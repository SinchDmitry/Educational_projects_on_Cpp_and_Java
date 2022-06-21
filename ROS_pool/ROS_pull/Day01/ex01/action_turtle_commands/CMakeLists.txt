cmake_minimum_required(VERSION 3.0.2)
project(action_turtle_commands)

find_package(catkin REQUIRED COMPONENTS 
	roscpp actionlib actionlib_msgs)
find_package(Boost REQUIRED COMPONENTS system)

add_action_files(
  DIRECTORY action
  FILES Message_turtle_commands.action
)

generate_messages(
  DEPENDENCIES actionlib_msgs std_msgs
)

catkin_package(
  CATKIN_DEPENDS actionlib_msgs
)

include_directories(include ${catkin_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})


add_executable(action_turtle_server src/action_turtle_server.cpp)

target_link_libraries(
	action_turtle_server
  ${catkin_LIBRARIES}
)

add_dependencies(
	action_turtle_server
  ${action_turtle_commands_EXPORTED_TARGETS}
)

add_executable(action_turtle_client src/action_turtle_client.cpp)

target_link_libraries( 
	action_turtle_client
  ${catkin_LIBRARIES}
)

add_dependencies(
  action_turtle_client
  ${action_turtle_commands_EXPORTED_TARGETS}
)
