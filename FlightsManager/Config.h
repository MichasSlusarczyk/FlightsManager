#pragma once
#include <string>

#include "Date.h"

/*Klasa przechowująca informacje na temat konfiguracji programu*/
class Config
{
public:
	std::string input;
	std::string output;
	std::string measure;
	std::string currency;
	Date lastLoginTime;
	Config();
};

