#pragma once
#include "Booking.h"
#include "Link.h"

/*Klasa przechowuj¹ca dane na temat biletu*/
class Ticket : public Booking, public Link
{
public:
	std::vector<std::string> flightPlaces;

	Ticket();
};

