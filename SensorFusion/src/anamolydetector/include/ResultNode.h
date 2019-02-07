/*
 * ResultNode.h
 *
 *  Created on: Dec 29, 2018
 *      Author: Team 2
 */


#include "ros/ros.h"
#include <time.h>
#include "anamolydetector/AnomolyData.h"

class ResultNode {
public:
	ResultNode();
	~ResultNode();
private:
	ros::NodeHandle nodeHandle;
	ros::Subscriber subscriber;
	void Callback(const anamolydetector::AnomolyData::ConstPtr& msg);
};

