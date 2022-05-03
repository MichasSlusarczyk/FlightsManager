#include "Validation.h"

void Validation::ValidationErrorManage(Error E)
{
    Print::PrintError(E);
}

bool Validation::ValidationYamlLine(std::string lineP)
{

    std::regex validationLine("(.+:.+)|(.+:)");

    if (std::regex_search(lineP, validationLine) == false)
    {
        ValidationErrorManage(E1);
        return false;
    }
 
    return true;

    
}

bool Validation::ValidationJsonLine(std::string lineP)
{
    std::regex validationLine("([[:blank:]]*\\{)|([[:blank:]]*\\}\\,?)|([[:blank:]]*\\[)|([[:blank:]]*\\]\\,?)|([[:blank:]]*\"[[:alnum:]]+\"\\:\\s\\[)|([[:blank:]]*\"[[:alnum:]]+\":\\.*)");

    if (std::regex_search(lineP, validationLine) == false)
    {
        ValidationErrorManage(E2);
        return false;
    }
    else
    {
        return true;
    }

}

bool Validation::ValidationFlightPlace(std::string fllightPlaceP, List<std::shared_ptr<Flight>>* flightsP, std::string placeP)
{

    std::regex validationLine("[[:alpha:]]+");

    if (std::regex_match(fllightPlaceP, validationLine) == false)
    {
        ValidationErrorManage(E3);
        return false;
    }

    bool flag = false;

    if (placeP == "From")
    {
        for (auto i = flightsP->Front(); i != nullptr; i = i -> pNext)
        {
            if ((*i).GetValue()->flightFrom == fllightPlaceP)
            {
                flag = true;
                break;
            }
        }

        if (flag == false)
        {
            ValidationErrorManage(E4);
            return false;
        }
    }
    else if (placeP == "Destination")
    {
        for (auto i = flightsP->Front(); i != nullptr; i= i -> pNext)
        {
            if ((*i).GetValue()->flightDestination == fllightPlaceP)
            {
                flag = true;
                break;
            }
        }

        if (flag == false)
        {
            ValidationErrorManage(E5);
            return false;
        }
    }

   return true;
}

bool Validation::ValidationFlightDate(Booking* booking, std::string fllightDateP, List<std::shared_ptr<Flight>>* flightsP, std::string placeP)
{

    std::regex validationLine("\\d\\d\\:\\d\\d\\s\\d\\d\\.\\d\\d\\.\\d\\d\\d\\d");

    if (std::regex_match(fllightDateP, validationLine) == false)
    {
        ValidationErrorManage(E6);
        return false;
    }

    bool flag = false;


    Date tempDate;
    tempDate.DateConvert(fllightDateP);

    if ((tempDate.day > 31 && tempDate.day < 1) || (tempDate.day > 12 && tempDate.day < 1) || (tempDate.year < 1) || (tempDate.hour > 23 && tempDate.hour < 0) || (tempDate.minute > 59 && tempDate.minute < 0))
    {
        ValidationErrorManage(E7);
        return false;
    }

    if (placeP == "From")
    {
        for (auto i = flightsP->Front(); i != nullptr; i = i-> pNext)
        {
            if ((*i).GetValue()->flightFrom == booking->flightFrom)
            {
                if (Date::DateCompare(tempDate, (*i).GetValue()->flightDeparture) == true)
                {
                    flag = true;
                    break;
                }
            }
        }
    }

    if (placeP == "Destination")
    {
        for (auto i = flightsP->Front(); i != nullptr; i = i->pNext)
        {
            if ((*i).GetValue()->flightDestination == booking->flightDestination)
            {
                if (Date::DateCompare((*i).GetValue()->flightArrival, tempDate) == true)
                {
                    flag = true;
                    break;
                }
            }
        }
    }

    if (flag == false)
    {
        ValidationErrorManage(E8);
        return false;
    }

    return true;

}

bool Validation::ValidationFlightImportant(std::string scaleP)
{

    std::regex validationLine("([1-9]{1})|(10)");

    if (std::regex_match(scaleP, validationLine) == false)
    {
        ValidationErrorManage(E9);
        return false;
    }

    return true;
}

bool Validation::ValidationUserName(std::string nameP)
{

    std::regex validationLine("[A-Z]{1}([a-z]+){1,}");

    if (std::regex_match(nameP, validationLine) == false)
    {
        ValidationErrorManage(E10);
        return false;
    }

    return true;
}

bool Validation::ValidationUserID(std::string idP)
{

    std::regex validationLine("[0-9]{11}");

    if (std::regex_match(idP, validationLine) == false)
    {
        ValidationErrorManage(E11);
        return false;
    }

    return true;
}