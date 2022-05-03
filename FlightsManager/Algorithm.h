#pragma once
#include <deque>
#include <memory>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <math.h>

#include "Booking.h"
#include "Link.h"
#include "List.h"

class Algorithm {

public:
	/*Wykonanie g��wnego algorytmu wyznaczja�cego po��czenia mi�dzy lokalizacja startow� a ko�cow�*/
	static bool AlgorithmMake(std::vector<Link>*, Booking*, List<std::shared_ptr<Flight>>*);

	/*Uszeregowanie po��cze� w oparciu o wynik punktowy*/
	static bool AlgorithmSortData(std::vector<Link>*, Booking*, List<std::shared_ptr<Flight>>*);

	/*Obiczenie wyniku punktowego na podstaiw wielokryterialnej funkcji celu*/
	static bool AlgorithmCountScore(std::vector<Link>*, Booking*);
};