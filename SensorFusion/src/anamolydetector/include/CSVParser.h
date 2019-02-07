/*
 * CSVParser.h
 *
 *  Created on: Dec 28, 2018
 *      Author: Team 2
 */

#include <sstream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <iostream>
#include <boost/algorithm/string.hpp>

using namespace std;

// typedefs, MACROS and enums

#define BASE 16
typedef std::vector<std::string> vecOfStrings;

enum
{
    ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT
};

class CSVParser {
private:
	std::string fileName;	//Variable for storing the CSV path
	std::string delimeter;

public:
	//Constructor
	CSVParser(std::string filename, std::string delm = ",");

	//Destructor
	~CSVParser();

	//Method for Parsing the CSV line by line
	std::vector< vecOfStrings > parseCSV();
};
