#pragma once
#include <deque>
#include <vector>
#include <memory>

#include "Link.h"
#include "Booking.h"
#include "Config.h"
#include "Date.h"
#include "Flight.h"
#include "Ticket.h"

#include "List.h"

/*Model przechowuj¹cy wszystkie dane na których operuje program*/
class Model
{
	friend class Management;
protected:
	List<std::shared_ptr<Flight>>* flights;
	std::vector<Link> link;
	std::unique_ptr<Config> config;

	std::unique_ptr<Booking> booking;
	std::unique_ptr<Ticket> ticket;

public:

	Model() 
	{
		flights = nullptr;
	}
};

