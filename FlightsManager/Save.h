#pragma once
#include "Model.h"
#include "Validation.h"

class Save
{
public:
	static bool SaveTicketCreate(Ticket*, Booking*, std::vector<Link>*,List<std::shared_ptr<Flight>>*, unsigned int);
	static bool SaveTicket(Ticket*,std::string, std::string);

};

