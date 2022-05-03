#include "LoadJson.h"


bool LoadJson::LoadJsonFlights(List<std::shared_ptr<Flight>>* flightsP, std::string pathP)
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


	int bracket = 0;
	int heading = 0;
	int squareBracket = 0;
	int zapis = 0;

	std::regex openBracket("[[:space:]]*\\{");
	std::regex headingRegex("[[:space:]]*\"[[:alnum:]]+\":\\s\\[");
	std::regex openSquareBracket("[[:space:]]*\\[");
	std::regex closeSquareBracket("[[:space:]]*\\]\\,*");
	std::regex closeBracket("[[:space:]]*\\}\\,*");
	std::regex yamlLine("[[:space:]]*[^:\\,\"]+");
	std::regex a("[[:blank:]]*\\}\\,*");


	int counter = 0;

	Flight tempFlight;

	while (!FILE.eof())
	{

		std::string tempString;
		std::getline(FILE, tempString);

		if (!Validation::ValidationJsonLine(tempString))
		{
			return false;
		}


		if (bracket == 2 && squareBracket == 1)
		{
			if (std::regex_search(tempString, a) == false)
			{
				std::vector<std::string> tempVectorString;

				auto it = std::sregex_iterator(tempString.begin(), tempString.end(), yamlLine);
				auto itEnd = std::sregex_iterator();

				for (std::sregex_iterator i = it; i != itEnd; ++i)
				{
					std::smatch match = *i;
					std::string match_str = match.str();
					std::regex a("[[:alnum:]]+");
					if (std::regex_search(match_str, a) == true)
					{
						tempVectorString.push_back(match_str);
					}
				}

				std::string jsonIndex = tempVectorString.front();
				std::string jsonValue = tempVectorString.back();

				LoadJsonFillData(flightsP, &tempFlight, tempVectorString, jsonIndex, jsonValue);
			}
			else
			{
				bracket--;
			}
		}
		else if (std::regex_match(tempString, openBracket))
		{
			bracket++;
		}
		else if (std::regex_match(tempString, headingRegex))
		{
			squareBracket++;
		}
		else if (std::regex_match(tempString, openSquareBracket))
		{
			squareBracket++;
		}
		else if (std::regex_match(tempString, closeBracket))
		{
			bracket--;
		}
		else if (std::regex_match(tempString, closeSquareBracket))
		{
			squareBracket--;
		}
	}


	if (bracket != 0 && squareBracket != 0)
	{
		return false;
	}


	return true;
}


bool LoadJson::LoadJsonFillData(List<std::shared_ptr<Flight>>* flightsP, Flight* tempFlightP, std::vector<std::string> tempVectorStringP, std::string indexP, std::string valueP)
{

	if (indexP == "flightFrom")
	{
		tempFlightP->flightFrom = valueP;
	}
	else if (indexP == "flightDestination")
	{
		tempFlightP->flightDestination = valueP;
	}
	else if (indexP == "flightDeparture")
	{
		valueP = tempVectorStringP[1] + ":" + tempVectorStringP[2];
		tempFlightP->flightDeparture.DateConvert(valueP);
	}
	else if (indexP == "flightArrival")
	{
		valueP = tempVectorStringP[1] + ":" + tempVectorStringP[2];
		tempFlightP->flightArrival.DateConvert(valueP);
	}
	else if (indexP == "Price")
	{
		tempFlightP->price = std::stof(valueP);
	}
	else if (indexP == "flightNumber")
	{
		tempFlightP->flightNumber = valueP;


		Flight* tempFlightToList = new Flight();
		*tempFlightToList = *tempFlightP;

		flightsP->PushBack(std::make_shared<Flight>(*tempFlightToList));

		delete tempFlightToList;
	}
	else {}

	return true;
}