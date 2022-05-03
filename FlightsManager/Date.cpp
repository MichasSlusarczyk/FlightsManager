#include "Date.h"


Date::Date()
{
	year = 0;
	month = 0;
	day = 0;
	hour = 0;
	minute = 0;
}

bool Date::DateConvert(std::string dateP)
{
	Date date;

	sscanf_s(dateP.c_str(), "%u:%u %u.%u.%u", &date.hour, &date.minute, &date.day, &date.month, &date.year);

	hour = date.hour;
	minute = date.minute;
	day = date.day;
	month = date.month;
	year = date.year;

	return true;
}

unsigned int Date::DateToMin(Date dateFromP, Date dateToP) 
{
	unsigned int timeSum =
		(dateToP.minute - dateFromP.minute) +
		60 * (dateToP.hour - dateFromP.hour) +
		24 * 60 * (dateToP.day - dateFromP.day) +
		31 * 24 * 60 * (dateToP.month - dateFromP.month) +
		12 * 31 * 24 * 60 * (dateToP.year - dateFromP.year);

	return timeSum;
}

bool Date::DateCompare(Date DateDatabase, Date DateUser)
{
	if (DateDatabase.year < DateUser.year)
	{
		return true;
	}
	else if (DateDatabase.year == DateUser.year)
	{
		if (DateDatabase.month < DateUser.month)
		{
			return true;
		}
		else if (DateDatabase.month == DateUser.month)
		{
			if (DateDatabase.day < DateUser.day)
			{
				return true;
			}
			else if (DateDatabase.day == DateUser.day)
			{
				if (DateDatabase.hour < DateUser.hour)
				{
					return true;
				}
				else if (DateDatabase.hour == DateUser.hour)
				{
					if (DateDatabase.minute < DateUser.minute)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
