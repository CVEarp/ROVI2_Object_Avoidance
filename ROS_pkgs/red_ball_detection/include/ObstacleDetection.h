// ROS 
#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <red_ball_detection/ballCentrum.h> // Created msg format
// OpenCV
#include <opencv2/opencv.hpp>
// General
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <string>
#include <numeric>

# define M_PI           3.14159265358979323846

using namespace std;
using namespace cv;

class ObstacleDetection {

  private:

	ros::NodeHandle nh_;
	image_transport::ImageTransport itp;

	// Publisher & Subscriber for images:
	image_transport::Subscriber img_subscriber;
	image_transport::Publisher img_publisher;

	// Obstacle 2D image coordinates Publisher
	ros::Publisher pub_coord;

	// Variables for the detector
	int kernel_size;
	int low_h;
	int high_h;
	string OPENCV_WINDOW;

  public:
	
	ObstacleDetection(const string sub_topic_name, const string pub_topic_name, const string pub_display);
	~ObstacleDetection();
	void cv_ros_iface(const sensor_msgs::ImageConstPtr& msg);
	void track_low_h(int,void*);
	void track_high_h(int,void*);
	void find_ball(cv::Mat img);
	

};

// Variables to define in main:
/*

	const string sub_topic_name;
	const string pub_topic_name;
	const string pub_display;
	const string window_name;

*/
