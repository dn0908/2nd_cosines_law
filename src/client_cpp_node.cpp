#include <ros/ros.h>
#include <2nd_cosines_law/ABAngle.h>

int main(int argc, char **argv) {
	ros::init(argc, argv, "ros_client");
	if (argc != 4)
	{
		ROS_INFO("usage: client_cpp_node a b angle(degree)");
		return 1;
	}
	ros::NodeHandle nh;
	ros::ServiceClient srv_client = nh.serviceClient<2nd_cosines_law::ABAngle>("/cosine_calc");

	2nd_cosines_law::ABAngle srv;
	srv.request.a = atof(argv[1]);
	srv.request.b = atof(argv[2]);
	srv.request.angle = atof(argv[3]) * M_PI / 180.;
	if (srv_client.call(srv))
		ROS_INFO("c = %lf", srv.response.c);
	else
	{
		ROS_ERROR("Failed to call service");
		return 1;
	}
	return 0;
} 
