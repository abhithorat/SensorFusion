/*
 * ResultNode.cpp
 *
 *  Created on: Dec 29, 2018
 *      Author: Team 2
 */

//#include "../../anomaly_detector/include/anomaly_detector/ResultNode.h"

#include "ResultNode.h"

ResultNode::ResultNode()
{
	subscriber = nodeHandle.subscribe("anomaly", 1000, &ResultNode::Callback, this);
}

ResultNode::~ResultNode()
{
}

void ResultNode::Callback(const anamolydetector::AnomolyData::ConstPtr& msg)
{
	ROS_INFO("Anomaly Status: %d",  msg->anomalyStatus);
	ROS_INFO("Time Received: %u",  msg->timeStamp);
	ROS_INFO("Message ID: %d", msg->msgId);
	time_t rawtime = msg->timeStamp;
	ROS_INFO("Human Readable Time Format: %s", ctime(&rawtime));
}


// Main Starts from Here
int main(int argc , char ** argv)
{
	  ros::init(argc, argv, "ResultNode");
	  ResultNode res;	//Required to call the constructor
	  ros::spin();
}
