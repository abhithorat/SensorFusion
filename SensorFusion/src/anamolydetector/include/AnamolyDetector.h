/*
 * AnamolyDetector.h
 *
 *  Created on: Jan 02, 2019
 *     Author: Atul and Yash
 */


#include "ros/ros.h"
#include "std_msgs/String.h"
#include "anamolydetector/AnomolyData.h"
#include "anamolydetector/CanMessage.h"
#include <string>

#include <sstream>

#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <queue>

using namespace std;

#define SAMPLING_RATE   3
#define MESSAGE_ID 234
#define MESSAGE_ID 251

enum {
 ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT
};

enum {
   CLOSE, OPEN
};

/*
 * Class : AnamolyDetector
 *
 * Purpose : to get data from input node,
 *  		 Process the received data for Anamoly detection,
 *  		 If Anamoly found advertise that to the output Node.
 */
class AnamolyDetector
{
public:
	AnamolyDetector();

	~AnamolyDetector()
	{
	}

	void processCanQueue(int );

private:
	void inputCallback(const anamolydetector::CanMessage::ConstPtr& msg);

	queue<anamolydetector::CanMessage> canQueue;
	ros::NodeHandle nodeHandle;
	ros::Publisher anomalyPublisher;
	ros::Subscriber inputSubscriber;
};

