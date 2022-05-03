#pragma once
#include <memory>
#include <deque>

#include "Booking.h"
#include "Save.h"

class User
{
	public:

	static bool UserGetData(Booking*, List<std::shared_ptr<Flight>>*);
	static bool UserFlightChoice(Booking*, std::vector<Link>*, List<std::shared_ptr<Flight>>*, Ticket*, std::string);
	static bool UserPrintTicket(Ticket*, std::string);
	static bool UserEndProgram();
};


