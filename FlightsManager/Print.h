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

	/*Wy�wietlenie kodu b��du wraz z opisem*/
	static void PrintError(Error);

	/*Wy�wietlenie przywitania*/
	static void PrintStart();

	/*Pobranie i wyswietlenie danych o lokalizacji startowej i ko�cowej*/
	static char PrintUserFlightDestination(Booking*, List<std::shared_ptr<Flight>>*);

	/*Pobranie i wyswietlenie danych o dacie wylotu i przylotu*/
	static char PrintUserFlightDate(Booking*, List<std::shared_ptr<Flight>>*);

	/*Pobranie i wyswietlenie danych na temat preferencji u�ytkownika*/
	static char PrintUserFlightImportant(Booking*, List<std::shared_ptr<Flight>>*);

	/*Pobranie i wyswietlenie danych osobowych u�ytkownika*/
	static char PrintUserData(Booking*);

	/*Wy�wietlenie wszystkich mo�liwych po��cze�*/
	static bool PrintUserLinks(std::vector<Link>*, List<std::shared_ptr<Flight>>*, std::string, unsigned int*);

	/*Wy�wietlenie interfejsu do poruszania si� po programie*/
	static char PrintUserMenu();

	/*Wyswietlenie daty*/
	static void PrintDate(Date);

	/*Wy�wietlenie biletu*/
	static void PrintTicket(Ticket*, std::string);

	/*Wy�wietlenie po�egnania*/
	static void PrintEnd();
};



