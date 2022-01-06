cmake_minimum_required(VERSION 2.8.3)
project(2nd_cosines_law)

# add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
	roscpp
	rospy
	std_msgs
	message_generation
)

add_service_files(
	FILES
	ABAngle.srv
)

generate_messages(
	DEPENDENCIES
	std_msgs
)

catkin_package()

include_directories(
# include
	${catkin_INCLUDE_DIRS}
)

add_executable(server_cpp_node src/server_cpp_node.cpp)
add_executable(client_cpp_node src/client_cpp_node.cpp)

add_dependencies(server_cpp_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(client_cpp_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(server_cpp_node ${catkin_LIBRARIES})
target_link_libraries(client_cpp_node ${catkin_LIBRARIES})
