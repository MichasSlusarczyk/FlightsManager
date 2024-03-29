#pragma once
#include <string>
#include "Flight.h"

/*Klasa przechowująca informacje pobrane przez użytkownika*/
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

