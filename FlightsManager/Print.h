#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <memory>
#include <deque>

#include "Error.h"
#include "Ticket.h"
#include "Link.h"
#include "Validation.h"
#include "Date.h"

#include "List.h"

class Print
{
public:

	/*Wyświetlenie kodu błędu wraz z opisem*/
	static void PrintError(Error);

	/*Wyświetlenie przywitania*/
	static void PrintStart();

	/*Pobranie i wyswietlenie danych o lokalizacji startowej i końcowej*/
	static char PrintUserFlightDestination(Booking*, List<std::shared_ptr<Flight>>*);

	/*Pobranie i wyswietlenie danych o dacie wylotu i przylotu*/
	static char PrintUserFlightDate(Booking*, List<std::shared_ptr<Flight>>*);

	/*Pobranie i wyswietlenie danych na temat preferencji użytkownika*/
	static char PrintUserFlightImportant(Booking*, List<std::shared_ptr<Flight>>*);

	/*Pobranie i wyswietlenie danych osobowych użytkownika*/
	static char PrintUserData(Booking*);

	/*Wyświetlenie wszystkich możliwych połączeń*/
	static bool PrintUserLinks(std::vector<Link>*, List<std::shared_ptr<Flight>>*, std::string, unsigned int*);

	/*Wyświetlenie interfejsu do poruszania się po programie*/
	static char PrintUserMenu();

	/*Wyswietlenie daty*/
	static void PrintDate(Date);

	/*Wyświetlenie biletu*/
	static void PrintTicket(Ticket*, std::string);

	/*Wyświetlenie pożegnania*/
	static void PrintEnd();
};



