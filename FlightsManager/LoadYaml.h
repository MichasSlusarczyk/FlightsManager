#pragma once

#include "Model.h"
#include "Validation.h"


class LoadYaml{
public:
	/*Wczytanie pliku konfiguracyjnego w formacie yaml*/
	static bool LoadYamlConfig(Config*, std::string);

	/*Rozpoznawanie danych z pliku*/
	static bool LoadYamlFillData(Config*, std::vector<std::string>, std::string, std::string);
};

