#!/usr/bin/env python

from 2nd_cosines_law.srv import *
import rospy
from math import sqrt, pow, cos, degrees

def handle_calc_c(req):
	print ("Calculating c using law of cosine request: %s %s %s")%(req.a, req.b, degrees(req.angle))
	res = ABAngleResponse()
	res.c = sqrt(pow(req.a,2) + pow(req.b,2) - 2*req.a*req.b*cos(req.angle))
	return res

def ros_calc_server():
	rospy.init_node('ros_server')
	s = rospy.Service('/cosine_calc', ABAngle, handle_calc_c)
	print ("Ready to calculate the c.")
	rospy.spin()


if __name__ == "__main__":
	ros_calc_server()
