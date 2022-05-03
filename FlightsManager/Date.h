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

	/*Metoda wyliczaj¹ca ile minut up³ynê³o od jednej daty do drugiej*/
	static unsigned int DateToMin(Date, Date);

	/*Porównanie która data wydarzy³a siê wczeœniej*/
	static bool DateCompare(Date, Date);
};

