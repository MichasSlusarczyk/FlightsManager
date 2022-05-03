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
	/*Wykonanie g³ównego algorytmu wyznaczja¹cego po³¹czenia miêdzy lokalizacja startow¹ a koñcow¹*/
	static bool AlgorithmMake(std::vector<Link>*, Booking*, List<std::shared_ptr<Flight>>*);

	/*Uszeregowanie po³¹czeñ w oparciu o wynik punktowy*/
	static bool AlgorithmSortData(std::vector<Link>*, Booking*, List<std::shared_ptr<Flight>>*);

	/*Obiczenie wyniku punktowego na podstaiw wielokryterialnej funkcji celu*/
	static bool AlgorithmCountScore(std::vector<Link>*, Booking*);
};