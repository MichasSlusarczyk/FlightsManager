#include <fstream>
#include <iostream>
#include <time.h>
#include <ctime>
#include <chrono>
#include <regex>
#include <vector>
#include <memory>

#include "LoadYaml.h"
#include "Date.h"
#include "Flight.h"

#include "List.h"




bool LoadYaml::LoadYamlConfig(Config* configP, std::string pathP)
{
	std::ifstream FILE;
	FILE.open(pathP.c_str(), std::ios::in);

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

	while (!FILE.eof())
	{
		std::string tempString;
		std::getline(FILE, tempString);

		if (!Validation::ValidationYamlLine(tempString))
		{
			return false;
		}

		std::vector<std::string> tempVectorString;

		std::regex yamlLine("[^:\"]+");

		auto it = std::sregex_iterator(tempString.begin(), tempString.end(), yamlLine);
		auto itEnd = std::sregex_iterator();


		for (std::sregex_iterator i = it; i != itEnd; ++i)
		{
			std::smatch match = *i;
			std::string match_str = match.str();
			if (match_str != " ")
			{
				tempVectorString.push_back(match_str);
			}
		}
			
		std::string yamlIndex = tempVectorString.front();
		std::string yamlValue = tempVectorString.back();


		LoadYamlFillData(configP, tempVectorString, yamlIndex, yamlValue);
	}

	FILE.close();

	return true;
}

bool LoadYaml::LoadYamlFillData(Config* configP, std::vector<std::string> tempVectorStringP, std::string indexP, std::string valueP)
{

	if (indexP == "input")
	{
		configP->input = valueP;
	}
	if (indexP == "output")
	{
		configP->output = valueP;
	}
	else if (indexP == "currency")
	{
		configP->currency = valueP;
	}
	else if (indexP == "measure")
	{
		configP->measure = valueP;
	}
	else if (indexP == "lastLogin")
	{
		valueP = tempVectorStringP[1] + ":" + tempVectorStringP[2];
		configP->lastLoginTime.DateConvert(valueP);
	}

	return true;
}