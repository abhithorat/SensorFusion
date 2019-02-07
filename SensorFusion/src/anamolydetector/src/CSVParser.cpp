/*
 * CSVParser.cpp
 *
 *  Created on: Dec 28, 2018
 *      Author: Team 2
 */

#include "CSVParser.h"

CSVParser::CSVParser(std::string filename, std::string delm ):fileName(filename), delimeter(delm)
{
	//Empty Body
}


std::vector<vecOfStrings> CSVParser::parseCSV()
{
	ifstream ifs;
	ifs.open(fileName.c_str(), ifstream::in);

	std::vector<vecOfStrings > dataList;

	std::string line = "";

	// Ignore first line as it does not have any data
	ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if( ifs.is_open() )
	{
	   // Iterate through each line and split the content using delimeter
	   while (getline(ifs, line))
	   {
		   std::vector<std::string> vec;
		   boost::algorithm::split(vec, line, boost::is_any_of(delimeter));
		   dataList.push_back(vec);
	   }
	   // Close the File
	   ifs.close();

	   return dataList;
	}
	else
	{
		cout << "File Open Error : Please Change the path in PublisherNode.cpp file & run again" << endl;
		exit(0);
	}
}
CSVParser::~CSVParser() {
	// TODO Auto-generated destructor

}

