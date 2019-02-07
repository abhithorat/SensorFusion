/*
 * PublisherNode.cpp
 *
 *  Created on: Dec 29, 2018
 *      Author: Team 2
 */

#include "CSVParser.h"
#include "PublisherNode.h"


PublisherNode::PublisherNode()
{
	inputPublisher = nodeHandle.advertise<anamolydetector::CanMessage>("inputData", 1000);
}

PublisherNode::~PublisherNode()
{
}

bool PublisherNode::PublishCANData()
{
	CSVParser file("/home/atul/Documents/Assignments/20180101_1555_22006_ECM_HSC1_FrP00_sync.csv");
	std::vector<vecOfStrings> dataList = file.parseCSV();
	ros::Rate loop_rate(1);

	anamolydetector::CanMessage msg;

	    // Send the input data to the Anomaly Detector node
	for(vecOfStrings vec : dataList)
	{

	   msg.msgId           =   stoi(vec[ONE], 0, 16);

	   msg.vehicleSpeed    = atof(vec[TWO].c_str());

	   msg.engineSpeed     = atof(vec[THREE].c_str());

	   msg.driverDoorOpen  = atoi(vec[FOUR].c_str());

	   msg.frontPassengerDoorOpen = atoi(vec[FIVE].c_str());

	   msg.rearLeftDoorOpen = atoi(vec[SIX].c_str());

	   msg.rearRightDoorOpen = atol(vec[SEVEN].c_str());

	   msg.timeStamp = atoi(vec[EIGHT].c_str());

	   inputPublisher.publish(msg);	//To publish the message

	   loop_rate.sleep();
	}
}

// Main Starts from Here
int main(int argc , char ** argv)
{
    ros::init(argc, argv, "PublisherNode"); // Publisher Node

    PublisherNode pNode;
    pNode.PublishCANData();

    return 0;

}
