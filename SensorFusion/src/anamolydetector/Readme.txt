This Project creates a new ROS package with name anamolydetector.

Inside anomalydetector package there are 3 Nodes and one Executable, executable inserts the data into CSV.

PublisherNode: This node reads the CSV file and anomaly inserted by  AnamolyInserter and publishes CAN data to topic.

AnamolyDetector:  Anomaly Detector node has the logic to determine if anomaly is present or not, in case if anomaly is present it will publish to topic and this topic will be subscribed by Result Node.

This node performs Anomaly detection taking Sampling Rate into account, if  theUser does not specify any value then default rate is 3.Otherwise default rate would be set to the passed Command Line Argument.

AnamolyInserter; This Executable Inserts the anomaly  to the existing CSV data.

ResultNode : This node will subscribe to the topic and will display the result with Time Frame published by AnamalyDetector node.

NOTE:
Before running catkin make the csv path in publisher.cpp has to be changed to appropriate path of the csv.
 

Steps:
Run the following commands:-
a.      Roscore
b.      ResultNode
c.      AnamolyDetector
d.      PublisherNode
