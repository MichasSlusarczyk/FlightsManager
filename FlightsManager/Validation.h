#pragma once
#include <string>
#include <regex>
#include <deque>
#include <memory>
#include <fstream>
#include <iterator>

#include "Print.h"
#include "Error.h"
#include "List.h"


/*Klasa odpowiedzialna za proces walidacji*/
class Validation 
{

public:

	/*Rozpoznaje b³¹d/wyj¹tek na podstawie kodu i wyœwietla komunikat*/
	static void ValidationErrorManage(Error);

	/*Walidacja danych z pliku Yaml*/
	static bool ValidationYamlLine(std::string);

	/*Walidacja danych z pliku Json*/
	static bool ValidationJsonLine(std::string);

	/*Walidacja lokalizacji lotu*/
	static bool ValidationFlightPlace(std::string, List<std::shared_ptr<Flight>>*, std::string);

	/*Walidacja daty lotu*/
	static bool ValidationFlightDate(Booking*, std::string, List<std::shared_ptr<Flight>>*, std::string);

	/*Walidacja preferencji u¿ytkownika*/
	static bool ValidationFlightImportant(std::string);

	/*Walidacja imienia i nazwiska*/
	static bool ValidationUserName(std::string);

	/*Walidacja peselu*/
	static bool ValidationUserID(std::string);
};



