#pragma once
#include <string>
#include "Flight.h"

/*Klasa przechowuj¹ca informacje pobrane przez u¿ytkownika*/
class Booking : public Flight
{
public:
	int flightTimeImportant;
	int flightPriceImportant;

	Date flightTimeArriveWant;
	Date flightTimeLeaveWant;

	std::string userFirstName;
	std::string userLastName;
	std::string userID;

	Booking();
};

