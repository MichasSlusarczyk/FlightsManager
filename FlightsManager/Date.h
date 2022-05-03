#pragma once
#include <string>
#include <stdio.h>

class Date
{
public:
	unsigned int year;
	unsigned int month;
	unsigned int day;
	unsigned int hour;
	unsigned int minute;

	/*Konstruktor*/
	Date();

	/*Mtoda konwertuje date jako string do formatu Daty*/
	bool DateConvert(std::string);

	/*Metoda wyliczaj�ca ile minut up�yn�o od jednej daty do drugiej*/
	static unsigned int DateToMin(Date, Date);

	/*Por�wnanie kt�ra data wydarzy�a si� wcze�niej*/
	static bool DateCompare(Date, Date);
};

