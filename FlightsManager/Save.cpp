#include <fstream>
#include <iostream>
#include <time.h>
#include <ctime>
#include <chrono>
#include <regex>
#include <vector>
#include <memory>

#include "Save.h"

bool Save::SaveTicketCreate(Ticket* ticketP, Booking* bookingP, std::vector<Link>* linksP, List<std::shared_ptr<Flight>>* flightsP, unsigned int option)
{
	for (auto i = linksP->begin(); i != linksP->end(); i++)
	{
		if ((*i).linkNumber == option)
		{
			std::vector<std::string> tempPlacesList;

			ticketP->fullPrice = (*i).fullPrice;
			ticketP->flightSwitch = (*i).flightSwitch;
			ticketP->timeInMin = (*i).timeInMin;
			ticketP->flightsList = (*i).flightsList;

            for (auto j = (*i).flightsList.begin(); j != (*i).flightsList.end(); j++)
            {
                for (auto k = flightsP->Front(); k != nullptr; k = k -> pNext)
                {
                    if ((*j) == (*k).GetValue()->flightNumber)
                    {
                        if ((*k).GetValue()->flightNumber == (*i).flightsList.front())
                        {
                            ticketP->flightDeparture = (*k).GetValue()->flightDeparture;
                        }

                        if ((*k).GetValue()->flightNumber == (*i).flightsList.back())
                        {
                            ticketP->flightArrival = (*k).GetValue()->flightArrival;
                        }

                        if ((*k).GetValue()->flightNumber == (*i).flightsList.front())
                        {
                            tempPlacesList.push_back((*k).GetValue()->flightFrom);
                            tempPlacesList.push_back((*k).GetValue()->flightDestination);
                        }
                        else
                        {
                            tempPlacesList.push_back((*k).GetValue()->flightDestination);
                        }
                    }
                }
            }

            ticketP->flightPlaces = tempPlacesList;
            ticketP->flightFrom = ticketP->flightPlaces.front();
            ticketP->flightDestination = ticketP->flightPlaces.back();

			ticketP->userFirstName = bookingP->userFirstName;
			ticketP->userLastName = bookingP->userLastName;
			ticketP->userID = bookingP->userID;

		}
	}

	return false;
}

bool Save::SaveTicket(Ticket* ticketP, std::string pathP, std::string currencyP)
{
	std::ofstream FILE;
	FILE.open(pathP.c_str(), std::ios::out);

	try
	{
		if (FILE.fail())
		{
			throw E12;
		}
	}
	catch (Error E)
	{
		Validation::ValidationErrorManage(E);
		return false;
	}

    FILE << "Dane osobowe:" << std::endl;
    FILE << "Imie: " << ticketP->userFirstName << std::endl;
    FILE << "Nazwisko: " << ticketP->userLastName << std::endl;
    FILE << "Pesel: " << ticketP->userID << std::endl << std::endl;

    FILE << "Informacje dotyczace lotu:" << std::endl;
    FILE << "Miejsce wylotu: " << ticketP->flightFrom << std::endl;
    FILE << "Miejsce przylotu: " << ticketP->flightDestination << std::endl;

    FILE << "Data wylotu: ";

    if (0 < ticketP->flightDeparture.hour && ticketP->flightDeparture.hour < 10)
    {
        FILE << "0" << ticketP->flightDeparture.hour << ":";
    }
    else
    {
        FILE << ticketP->flightDeparture.hour << ":";
    }

    if (0 < ticketP->flightDeparture.minute && ticketP->flightDeparture.minute < 10)
    {
        FILE << "0" << ticketP->flightDeparture.minute;
    }
    else
    {
        FILE << ticketP->flightDeparture.minute;
    }

    FILE << " " << ticketP->flightDeparture.day << "." << ticketP->flightDeparture.month << "." << ticketP->flightDeparture.year;
    FILE << std::endl;
    FILE << "Data przylotu: ";

    if (0 < ticketP->flightArrival.hour && ticketP->flightArrival.hour < 10)
    {
        FILE << "0" << ticketP->flightArrival.hour << ":";
    }
    else
    {
        FILE << ticketP->flightArrival.hour << ":";
    }

    if (0 < ticketP->flightArrival.minute && ticketP->flightArrival.minute < 10)
    {
        FILE << "0" << ticketP->flightArrival.minute;
    }
    else
    {
        FILE << ticketP->flightArrival.minute;
    }

    FILE << " " << ticketP->flightArrival.day << "." << ticketP->flightArrival.month << "." << ticketP->flightArrival.year;
    FILE << std::endl;

    FILE << "Czas podrozy w minutach: " << ticketP->timeInMin << std::endl;

    FILE << "Przez: ";
    for (auto i = ticketP->flightPlaces.begin(); i != ticketP->flightPlaces.end(); i++)
    {
        if ((*i) != ticketP->flightPlaces.back())
        {
            FILE << (*i) << "->";
        }
        else
        {
            FILE << (*i);
        }
    }
    FILE << std::endl;

    FILE << "Numery lotow: ";
    for (auto i = ticketP->flightsList.begin(); i != ticketP->flightsList.end(); i++)
    {
        if ((*i) != ticketP->flightsList.back())
        {
            FILE << (*i) << ", ";
        }
        else
        {
            FILE << (*i);
        }
    }

    FILE << "Liczba przesiadek: " << ticketP->flightSwitch << std::endl;
    FILE << "Cena za podroz: " << ticketP->fullPrice << " " << currencyP << std::endl << std::endl;


		
	FILE.close();

	return true;
}
