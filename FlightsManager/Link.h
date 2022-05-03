#pragma once
#include <vector>
#include <string>

/*Klasa przechowująca informacje na temat połączenia*/
class Link
{
public:
	std::vector<std::string> flightsList;
	unsigned int timeInMin;
	unsigned int flightSwitch;
	float fullPrice;

	float score;

	unsigned int linkNumber;

	Link();
};

