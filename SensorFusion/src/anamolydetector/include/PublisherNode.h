/*
 * PublisherNode.h
 *
 *  	Created on: Dec 29, 2018
 *      Author: Team 2
 */


#include <iostream>
#include <string>
#include <stdlib.h>

#include "ros/ros.h"
#include "anamolydetector/CanMessage.h"

using namespace std;

class PublisherNode {
private:
	ros::NodeHandle nodeHandle;
	ros::Publisher  inputPublisher;

public:
	PublisherNode();
	~PublisherNode();
	bool PublishCANData();
};
