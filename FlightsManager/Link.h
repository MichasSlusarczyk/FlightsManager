#pragma once
#include <vector>
#include <string>

/*Klasa przechowuj¹ca informacje na temat po³¹czenia*/
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

