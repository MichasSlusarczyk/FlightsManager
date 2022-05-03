#include "User.h"
#include "List.h"
#include "Print.h"


bool User::UserGetData(Booking* bookingsP, List<std::shared_ptr<Flight>>* flightsP)
{
    int it = 1;
    char option;

    while (it <= 5)
    {
        switch (it)
        {
        case 0:
            return true;
            break;
        case 1:
            //Menu startowe: JEST
            Print::PrintStart();
            option = 'n';
            break;
        case 2:
            //Podaj dane lotu po kolei: sk¹d, dok¹d, JEST
            option = Print::PrintUserFlightDestination(bookingsP, flightsP);
            break;
        case 3:
            //Kiedy (rok, miesi¹c, dzieñ), JEST
            option = Print::PrintUserFlightDate(bookingsP, flightsP);
            break;
        case 4:
            //Podaj jak bardzo zale¿y Ci na czasie, a jak bardzo na cenie i czy pasuj¹ przesiadki, JEST
            option = Print::PrintUserFlightImportant(bookingsP, flightsP);
            break;
        case 5:
            //Podaj jak bardzo zale¿y Ci na czasie, a jak bardzo na cenie i czy pasuj¹ przesiadki, JEST
            option = Print::PrintUserData(bookingsP);
            break;
        default:
            return false;
        }

        if (option == 'q')
        {
            it = 0;
        }
        else if (option == 'n')
        {
            it++;
        }
        else if (option == 'b')
        {
            it--;
        }
    }


    return false;
}

bool User::UserFlightChoice(Booking* bookingP, std::vector<Link>* linksP, List<std::shared_ptr<Flight>>* flightsP, Ticket* ticketP, std::string currencyP)
{
    unsigned int option;

    Print::PrintUserLinks(linksP, flightsP, currencyP, &option);

    if (option == 0)
    {
        return false;
    }
    else
    {
        Save::SaveTicketCreate(ticketP, bookingP, linksP, flightsP, option);
    }

    return true;
}

bool User::UserEndProgram()
{


    Print::PrintEnd();

    return true;
}

bool User::UserPrintTicket(Ticket* ticketP, std::string currencyP)
{

    if (ticketP->flightPlaces.size() != 0)
    {
        Print::PrintTicket(ticketP, currencyP);
    }

    return true;
}