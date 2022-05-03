#include "Algorithm.h"

bool Algorithm::AlgorithmMake(std::vector<Link>* linkP, Booking* bookingP, List<std::shared_ptr<Flight>>* flightsP)
{
	// Zmienne pomocnicze
	Date timeDeparture = bookingP->flightTimeLeaveWant;
	Date timeArrival = bookingP->flightTimeArriveWant;
	std::string from = bookingP->flightFrom;
	std::string destination = bookingP->flightDestination;

	std::vector<Link> possibleLinks;

	for (auto i = flightsP->Front(); i != nullptr; i=i->pNext)
	{
		// je�li to miasto startowe i wylot jest po podanej dacie rozpoczecia podr�y
		if ((*i).GetValue()->flightFrom == from && Date::DateCompare(timeDeparture, (*i).GetValue()->flightDeparture))
		{
			//je�li jest bezpo�redni zgodny
			if ((*i).GetValue()->flightDestination==destination && Date::DateCompare((*i).GetValue()->flightArrival, timeArrival))
			{
				Link tempLink;
				tempLink.flightsList.push_back((*i).GetValue()->flightNumber);
				possibleLinks.push_back(tempLink);
			}
			else //w inny przypadku
			{

				std::deque<std::vector<Flight>>  tempLinks;

				std::vector<Flight> tempVec;
				tempVec.push_back(*(*i).GetValue());
				tempLinks.push_back(tempVec);

				while (!tempLinks.empty()) //p�ki nie rozwa�yli�my wszystkich mo�liwo�ci
				{

					for (auto j = tempLinks.begin(); j != tempLinks.end(); j++) //iterowanie po �cie�kach
					{
						for (auto k = flightsP->Front(); k != nullptr; k = k->pNext) //iterowanie po wszystkich lotach kt�re spr�bujemy dopasowa� do �cie�ek
						{
							bool flagPlaces = true;


							//iterowanie po wszystkich lotach ze �cie�ki
							for (auto l = (*j).begin(); l != (*j).end(); l++)
							{
								//czy nie byli�my ju� przypadkiem w tym mie�cie
								if (((*k).GetValue()->flightFrom == l->flightFrom) ||
									((*k).GetValue()->flightDestination == l->flightFrom) ||
									((*k).GetValue()->flightFrom == destination))
								{
									flagPlaces = false;
									break;
								}
							}

							bool flagTime = false;
							bool flagTimeFirst = false;
							bool flagTimeSecond = false;

							//po zako�czeniu poprzedniego lotu data rozpoczecia kolejnego lotu
							if (Date::DateCompare((*j).back().flightArrival,(*k).GetValue()->flightDeparture))
							{
								flagTimeFirst = true;
							}

							//je�li koniec nowego lotu jest przed zamierzon� dat� ko�ca podr�y
							if (Date::DateCompare((*k).GetValue()->flightDeparture, timeArrival))
							{
								flagTimeSecond = true;
							}

							if (flagTimeFirst == true && flagTimeSecond == true)
							{
								flagTime = true;
							}

							if (flagPlaces == true && flagTime == true)
							{
								//skopiowac �cie�ke i doda� miasto, i doda� na pocz�tek list �cie�ek
								std::vector<Flight> newPossibleLink;

								for (unsigned int it = 0; it < (*j).size(); it++)
								{
									newPossibleLink.push_back((*j)[it]); //przepisanie danych
								}
								newPossibleLink.push_back(*(*k).GetValue().get()); //dodanie nowego lotu

								//albo dodac jako wynikowa i usun��
								if (newPossibleLink.back().flightDestination == destination) //je�li jest bezpo�redni zgodny
								{
									Link tempLink;
									for (auto m = newPossibleLink.begin(); m != newPossibleLink.end(); m++)
									{
										tempLink.flightsList.push_back((*m).flightNumber);
									}
									possibleLinks.push_back(tempLink);
								}
								else
								{
									tempLinks.push_back(newPossibleLink); // dodanie do potencjalnych �ciezek
								}
							}
						}
					}
					//usuniecie starej sciezki
					tempLinks.erase(tempLinks.begin());
				}
			}
		}

	}


	*linkP = possibleLinks;

	return true;
}

bool Algorithm::AlgorithmCountScore(std::vector<Link>* linkP, Booking* bookingP)
{
	for (auto i = (*linkP).begin(); i != (*linkP).end(); i++) // iterowanie po wszystkich �cie�kach
	{
		(*i).score = (*i).fullPrice * bookingP->flightPriceImportant + (*i).timeInMin * bookingP->flightTimeImportant;
		(*i).score = (*i).score + (*i).score * (1 / 3) * ((*i).flightSwitch - 1);
	}

	return true;
}

bool Algorithm::AlgorithmSortData(std::vector<Link>* linkP, Booking* bookingP, List<std::shared_ptr<Flight>>* flightsP)
{

	for (auto i = (*linkP).begin(); i != (*linkP).end(); i++) // iterowanie po wszystkich �cie�kach
	{
		(*i).flightSwitch = (*i).flightsList.size();


		std::string tempFlightFrom = (*i).flightsList.front();
		std::string tempFlightTo = (*i).flightsList.back();

		Date firstFlightDeparture;
		Date lastFlightArrival;

		for (auto j = (*i).flightsList.begin(); j != (*i).flightsList.end(); j++) // iterowanie po lotach w �cie�kach
		{
			for (auto k = flightsP->Front(); k != nullptr; k = k->pNext) // iterowanie po wszystkich lotach
			{
				if ((*j) == (*k).GetValue()->flightNumber)
				{
					(*i).fullPrice += (*k).GetValue()->price;
				}

				if (tempFlightFrom == (*k).GetValue()->flightNumber)
				{
					firstFlightDeparture = (*k).GetValue()->flightDeparture;
				}

				if (tempFlightTo == (*k).GetValue()->flightNumber)
				{
					lastFlightArrival = (*k).GetValue()->flightArrival;
				}
			}
		}


		(*i).fullPrice = floor((*i).fullPrice * 100) / 100;
		(*i).timeInMin = Date::DateToMin(firstFlightDeparture, lastFlightArrival);
	}

	//Obliczenie scora
	AlgorithmCountScore(linkP, bookingP);

	//Uszeregowanie malej�co
	for (size_t i = 0; i < linkP->size(); i++) // iterowanie po wszystkich �cie�kach
	{
		for (size_t j = 1; j < (linkP->size() - i); j++) //p�tla wewn�trzna
		{
			if ((*linkP)[j - 1].score > (*linkP)[j].score)
			{
				//zamiana miejscami
				std::swap((*linkP)[j - 1], (*linkP)[j]);
			}
		}
	}

	std::cout << "a";

	return true;
}