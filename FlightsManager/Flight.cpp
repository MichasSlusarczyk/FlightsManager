#include "Flight.h"

Flight::Flight()
{
	this->flightFrom = "";
	this->flightDestination = "";
	this->price = 0;
	this->flightNumber = "";

	this->flightDeparture = Date();
	this->flightArrival = Date();
}
