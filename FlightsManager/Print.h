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

	/*Wyœwietlenie kodu b³êdu wraz z opisem*/
	static void PrintError(Error);

	/*Wyœwietlenie przywitania*/
	static void PrintStart();

	/*Pobranie i wyswietlenie danych o lokalizacji startowej i koñcowej*/
	static char PrintUserFlightDestination(Booking*, List<std::shared_ptr<Flight>>*);

	/*Pobranie i wyswietlenie danych o dacie wylotu i przylotu*/
	static char PrintUserFlightDate(Booking*, List<std::shared_ptr<Flight>>*);

	/*Pobranie i wyswietlenie danych na temat preferencji u¿ytkownika*/
	static char PrintUserFlightImportant(Booking*, List<std::shared_ptr<Flight>>*);

	/*Pobranie i wyswietlenie danych osobowych u¿ytkownika*/
	static char PrintUserData(Booking*);

	/*Wyœwietlenie wszystkich mo¿liwych po³¹czeñ*/
	static bool PrintUserLinks(std::vector<Link>*, List<std::shared_ptr<Flight>>*, std::string, unsigned int*);

	/*Wyœwietlenie interfejsu do poruszania siê po programie*/
	static char PrintUserMenu();

	/*Wyswietlenie daty*/
	static void PrintDate(Date);

	/*Wyœwietlenie biletu*/
	static void PrintTicket(Ticket*, std::string);

	/*Wyœwietlenie po¿egnania*/
	static void PrintEnd();
};



