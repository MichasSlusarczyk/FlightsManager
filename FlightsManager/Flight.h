#pragma once
#include <string>

#include "Date.h"

/*Klasa przechowująca informacje na temat lotu*/
class Flight
{
public:
	std::string flightFrom;
	std::string flightDestination;
	Date flightDeparture;
	Date flightArrival;

	float price;
	std::string flightNumber;

	Flight();
};

