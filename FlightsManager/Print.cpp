#include "Print.h"

void Print::PrintError(Error E)
{
    std::cout << std::endl;

    switch (E) {
    case E0:
        std::cout << "Blad/wyjatek" << "E" << E <<": " << "" << std::endl;
        // code block
        break;
    case E1:
        std::cout << "Blad/wyjatek" << "E" << E << ": " << "Nieprawidlowy format tekstu w pliku Yaml!" << std::endl;
        // code block
        break;
    case E2:
        std::cout << "Blad/wyjatek" << "E" << E << ": " << "Nieprawidlowy format tekstu w pliku Json!" << std::endl;
        // code block
        break;
    case E3:
        std::cout << "Blad/wyjatek" << "E" << E << ": " << "Nieprawidlowe dane!" << std::endl;
        // code block
        break;
    case E4:
        std::cout << "Blad/wyjatek" << "E" << E << ": " << "Brak takiej lokacji startowej w bazie lotow!" << std::endl;
        // code block
        break;
    case E5:
        std::cout << "Blad/wyjatek" << "E" << E << ": " << "Brak takiej lokacji koncowej w bazie lotow!" << std::endl;
        // code block
        break;
    case E6:
        std::cout << "Blad/wyjatek" << "E" << E << ": " << "Niprawidlowy format daty!" << std::endl;
        // code block
        break;
    case E7:
        std::cout << "Blad/wyjatek" << "E" << E << ": " << "Niepoprawna data!" << std::endl;
        // code block
        break;
    case E8:
        std::cout << "Blad/wyjatek" << "E" << E << ": " << "Brak poszukiwanego lotu w bazie!" << std::endl;
        // code block
        break;
    case E9:
        std::cout << "Blad/wyjatek" << "E" << E << ": " << "Niepoprawna wartosc!" << std::endl;
        // code block
        break;
    case E10:
        std::cout << "Blad/wyjatek" << "E" << E << ": " << "Niepoprawne imie/nazwisko!" << std::endl;
        // code block
        break;
    case E11:
        std::cout << "Blad/wyjatek" << "E" << E << ": " << "Niepoprawny pesel!" << std::endl;
        // code block
        break;
    case E12:
        std::cout << "Blad/wyjatek" << "E" << E << ": " << "Blad podczas wczytywania pliku!" << std::endl;
        // code block
        break;
    default:
        std::cout << "Nieznany kod bledu. Skontaktuj sie z administratorem systemu!" << std::endl;
    }
}

void Print::PrintStart()
{
    std::cout << "Witamy w aplikacji rezerwujacej bilety poskich linii lotniczych NIELOT!" << std::endl;
    Sleep(3000);
    system("cls");
}

char Print::PrintUserFlightDestination(Booking* bookingP, List<std::shared_ptr<Flight>>* flightsP)
{
    std::string tempFlightFrom;
    std::cout << "Podaj nazwe miejsca z ktorego chcesz wyleciec: ";
    std::cin >> tempFlightFrom;

    if (Validation::ValidationFlightPlace(tempFlightFrom, flightsP, "From") == false)
    {
        std::cout << "Nieprawidlowe miejsce wylotu. Podaj lokacje jeszcze raz!" << std::endl;
        Sleep(4000);
        system("cls");

        return 'r';
    }
    else
    {
        bookingP->flightFrom = tempFlightFrom;

        std::string tempFlightDestination;
        std::cout << "Podaj nazwe miejsca do ktorego chcesz leciec: ";
        std::cin >> tempFlightDestination;

        if (Validation::ValidationFlightPlace(tempFlightDestination, flightsP, "Destination") == false)
        {
            std::cout << "Nieprawidlowe miejsce docelowe. Podaj lokacje jeszcze raz!" << std::endl;
            Sleep(4000);
            system("cls");

            return 'r';
        }
        else
        {
            bookingP->flightDestination = tempFlightDestination;
        }
    }

    system("cls");
    char option = PrintUserMenu();

    return option;
}

char Print::PrintUserFlightDate(Booking* bookingP, List<std::shared_ptr<Flight>>* flightsP)
{
    std::string tempFlightDateFrom;
    std::cout << "Podaj date na od ktorej szukac lotu w formacie \"dd.mm.rrrr\": ";
    std::cin >> tempFlightDateFrom;

    std::string tempFlightTimeFrom;
    std::cout << "Podaj godzine na od ktorej szukac lotu w formacie \"gg:mm\": ";
    std::cin >> tempFlightTimeFrom;

    tempFlightDateFrom = tempFlightTimeFrom + " " + tempFlightDateFrom;

    if (Validation::ValidationFlightDate(bookingP, tempFlightDateFrom, flightsP, "From") == false)
    {
        std::cout << "Nieprawidlowa data. Podaj date jeszcze raz!" << std::endl;
        Sleep(4000);
        system("cls");

        return 'r';
    }
    else
    {
        bookingP->flightTimeLeaveWant.DateConvert(tempFlightDateFrom);

        std::string tempFlightDateDest;
        std::cout << "Podaj date na kiedy chcesz byc na miejscu w formacie \"dd.mm.rrrr\": ";
        std::cin >> tempFlightDateDest;

        std::string tempFlightTimeDest;
        std::cout << "Podaj godzine na kiedy chcesz byc na miejscu w formacie \"gg:mm\": ";
        std::cin >> tempFlightTimeDest;

        tempFlightDateDest = tempFlightTimeDest + " " + tempFlightDateDest;

        if (Validation::ValidationFlightDate(bookingP, tempFlightDateDest, flightsP, "Destination") == false)
        {
            std::cout << "Nieprawidlowa data. Podaj date jeszcze raz!" << std::endl;
            Sleep(4000);
            system("cls");

            return 'r';
        }
        else
        {
            bookingP->flightTimeArriveWant.DateConvert(tempFlightDateDest);
        }
    }

    system("cls");
    char option = PrintUserMenu();

    return option;
}

char Print::PrintUserFlightImportant(Booking* bookingP, List<std::shared_ptr<Flight>>* flightsP)
{
    std::string tempFlightPriceImp;
    std::cout << "W skali od 1 do 10 opisz jak istotna jest cena przelotu: ";
    std::cin >> tempFlightPriceImp;

    if (Validation::ValidationFlightImportant(tempFlightPriceImp) == false)
    {
        std::cout << "Nieprawidlowe dane! Podaj odpowiedz jeszcze raz!" << std::endl;
        Sleep(4000);
        system("cls");

        return 'r';
    }
    else
    {
        bookingP->flightPriceImportant = stoi(tempFlightPriceImp);

        std::string tempFlightDateImp;
        std::cout << "W skali od 1 do 10 opisz jak istotny jest czas przelotu: ";
        std::cin >> tempFlightDateImp;

        if (Validation::ValidationFlightImportant(tempFlightDateImp) == false)
        {
            std::cout << "Nieprawidlowe dane! Podaj odpowiedz jeszcze raz!" << std::endl;
            Sleep(4000);
            system("cls");

            return 'r';
        }
        else
        {
            bookingP->flightTimeImportant = stoi(tempFlightDateImp);
        }
    }


    system("cls");
    char option = PrintUserMenu();

    return option;
}

char Print::PrintUserData(Booking* bookingP)
{
    std::cout << "Dane osobowe:" << std::endl << std::endl;

    std::string tempUserFirstName;
    std::cout << "Podaj swoje imie: ";
    std::cin >> tempUserFirstName;

    if (Validation::ValidationUserName(tempUserFirstName) == false)
    {
        std::cout << "Nieprawidlowe dane! Podaj odpowiedz jeszcze raz!" << std::endl;
        Sleep(4000);
        system("cls");

        return 'r';
    }
    else
    {
        bookingP->userFirstName = tempUserFirstName;

        std::string tempUserLastName;
        std::cout << "Podaj swoje nazwisko: ";
        std::cin >> tempUserLastName;

        if (Validation::ValidationUserName(tempUserLastName) == false)
        {
            std::cout << "Nieprawidlowe imie! Podaj odpowiedz jeszcze raz!" << std::endl;
            Sleep(4000);
            system("cls");

            return 'r';
        }
        else
        {
            bookingP->userLastName = tempUserLastName;

            std::string tempUserID;
            std::cout << "Podaj swoj pesel: ";
            std::cin >> tempUserID;

            if (Validation::ValidationUserID(tempUserID) == false)
            {
                std::cout << "Nieprawidlowy pesel! Podaj odpowiedz jeszcze raz!" << std::endl;
                Sleep(4000);
                system("cls");

                return 'r';
            }
            else
            {
                bookingP->userID = tempUserID;
            }
        }
    }


    system("cls");
    char option = PrintUserMenu();

    return option;
}

bool Print::PrintUserLinks(std::vector<Link>* linksP, List<std::shared_ptr<Flight>>* flightsP, std::string currencyP, unsigned int* optionP)
{
    system("cls");
    std::cout << "Lista znalezionych polaczen!:" << std::endl << std::endl;

    unsigned int it = 1;

    for (auto i = linksP->begin(); i != linksP->end(); i++)
    {

        (*i).linkNumber = it;
        it++;

        std::vector<std::string> templinksNames;
        Date dateFrom;
        Date dateTo;

        for (auto j = (*i).flightsList.begin(); j != (*i).flightsList.end(); j++)
        {
            for (auto k = flightsP->Front(); k != nullptr; k = k -> pNext)
            {
                if ((*j) == (*k).GetValue()->flightNumber)
                {
                    if ((*k).GetValue()->flightNumber == (*i).flightsList.front())
                    {
                        dateFrom = (*k).GetValue()->flightDeparture;
                    }

                    if ((*k).GetValue()->flightNumber == (*i).flightsList.back())
                    {
                        dateTo = (*k).GetValue()->flightArrival;
                    }

                    if ((*k).GetValue()->flightNumber == (*i).flightsList.front())
                    {
                        templinksNames.push_back((*k).GetValue()->flightFrom);
                        templinksNames.push_back((*k).GetValue()->flightDestination);
                    }
                    else
                    {
                        templinksNames.push_back((*k).GetValue()->flightDestination);
                    }
                }
            }
        }

        std::cout << "Numer polaczenia: " << (*i).linkNumber <<std::endl;
        std::cout << "Lokalizacja startowa: " << templinksNames.front() << std::endl;
        std::cout << "Lokalizacja koncowa: " << templinksNames.back() << std::endl;

        std::cout << "Przez: ";
        if (templinksNames.size() == 2)
        {
            std::cout << "Bezposredni" << std::endl;
        }
        else if (templinksNames.size() > 2)
        {
            for (auto j = templinksNames.begin(); j != templinksNames.end(); j++)
            {
                if ((*j) != templinksNames.back())
                {
                    std::cout << (*j) << "->";
                }
                else
                {
                    std::cout << (*j);
                }
            }
            std::cout << std::endl;
        }

        std::cout << "Data wylotu: ";
        PrintDate(dateFrom);
        std::cout << std::endl;

        std::cout << "Data przylotu: ";
        PrintDate(dateTo);
        std::cout << std::endl;

        std::cout << "Czas podrozy w minutach: " << (*i).timeInMin << std::endl;
        std::cout << "Liczba przesiadek: " << (*i).flightSwitch << std::endl;
        std::cout << "Cena za podroz: " << (*i).fullPrice << " " << currencyP << std::endl;

        std::cout << std::endl << std::endl;

    }

    std::string option;
    std::cout << "Wcisnij q jesli chcesz zrezygnowac lub wpisz numer lotu na ktory chcesz zarezerwowac bilet: ";
    std::cin >> option;

    system("cls");

    if (0<std::atoi(option.c_str()) && std::atoi(option.c_str())<=linksP->size())
    {
        *optionP = std::atoi(option.c_str());
        return true;
    }
    else
    {
        *optionP = 0;
        return true;
    }


    return false;
}

char Print::PrintUserMenu()
{
    std::cout << "Aby zrezygnowac wcisnij 'q'!" << std::endl;
    std::cout << "Aby powtorzyc wcisnij 'r'!" << std::endl;
    std::cout << "Aby powrocic wcisnij 'b'!" << std::endl;
    std::cout << "Aby przejsc dalej wcisnij 'n'!" << std::endl << std::endl;

    char option;

    std::cout << "WYBOR: ";

    std::cin >> option;

    system("cls");
    
    if (option == 'r')
    {
        return 'r';
    }
    else if (option == 'q')
    {
        return 'q';
    }
    else if (option == 'n')
    {
        return 'n';
    }
    else if (option == 'b')
    {
        return 'b';
    }
    else
    {
        system("cls");
        option = PrintUserMenu();
        return option;
    }

    return 'q';
}

void Print::PrintDate(Date dateP)
{
    if (0 < dateP.hour && dateP.hour < 10)
    {
        std::cout << "0" << dateP.hour << ":";
    }
    else
    {
        std::cout << dateP.hour << ":";
    }

    if (0 < dateP.minute && dateP.minute < 10)
    {
        std::cout << "0" << dateP.minute;
    }
    else
    {
        std::cout << dateP.minute;
    }

    std::cout << " " << dateP.day << "." << dateP.month << "." << dateP.year;
}

void Print::PrintTicket(Ticket* ticketP, std::string currencyP)
{
    system("cls");

    std::cout << "Zarezerwowany bilet lotniczy:" << std::endl << std::endl;

    std::cout << "Dane osobowe:" << std::endl;
    std::cout << "Imie: " << ticketP->userFirstName << std::endl;
    std::cout << "Nazwisko: " << ticketP->userLastName << std::endl;
    std::cout << "Pesel: " << ticketP->userID << std::endl << std::endl;

    std::cout << "Informacje dotyczace lotu:" << std::endl;
    std::cout << "Miejsce wylotu: " << ticketP->flightFrom << std::endl;
    std::cout << "Miejsce przylotu: " << ticketP->flightDestination << std::endl;

    std::cout << "Data wylotu: ";
    PrintDate(ticketP->flightDeparture);
    std::cout << std::endl;
    std::cout << "Data przylotu: ";
    PrintDate(ticketP->flightArrival);
    std::cout << std::endl;

    std::cout << "Czas podrozy w minutach: " << ticketP->timeInMin << std::endl;

    std::cout << "Przez: ";

    for (auto i = ticketP->flightPlaces.begin(); i != ticketP->flightPlaces.end(); i++)
    {
        if ((*i) != ticketP->flightPlaces.back())
        {
            std::cout << (*i) << "->";
        }
        else
        {
            std::cout << (*i);
        }
    }
    std::cout << std::endl;

    std::cout << "Numery lotow: ";
    for (auto i = ticketP->flightsList.begin(); i != ticketP->flightsList.end(); i++)
    {
        if ((*i) != ticketP->flightsList.back())
        {
            std::cout << (*i) << ", ";
        }
        else
        {
            std::cout << (*i);
        }
    }

    std::cout << std::endl;

    std::cout << "Liczba przesiadek: " << ticketP->flightSwitch << std::endl;
    std::cout << "Cena za podroz: " << ticketP->fullPrice << " " << currencyP << std::endl << std::endl;

    std::cout << "Wpisz tu cokolwiek gdy juz przeczytasz zawartosc biletu: ";
    std::string wait;
    std::cin >> wait;

    system("cls");
}

void Print::PrintEnd()
{
    system("cls");

    std::cout << "Dziekujemy za skorzystanie z polskich linii lotniczych Nielot!" << std::endl << std::endl;

    Sleep(4000);

    system("cls");
}
