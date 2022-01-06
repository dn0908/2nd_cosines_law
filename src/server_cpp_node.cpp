#include <ros/ros.h>
#include <2nd_cosines_law/ABAngle.h>
#include <cmath>

using namespace std;

bool service_callback(2nd_cosines_law::ABAngle::Request &req,
					  2nd_cosines_law::ABAngle::Response &res)
{
	res.c = sqrt(pow(req.a,2) + pow(req.b,2) - 2*req.a*req.b*cos(req.angle));
	ROS_INFO("Calculating c using law of cosine request: %.1lf %.1lf %.1lf", 
			req.a, req.b, req.angle * 180.0 / M_PI);
	return true;
}

int main(int argc, char **argv) {
	ros::init(argc, argv, "ros_server");
	ros::NodeHandle nh; 
	ros::ServiceServer srv_server = nh.advertiseService("/cosine_calc", service_callback);
	ros::spin();
	return 0;
}
