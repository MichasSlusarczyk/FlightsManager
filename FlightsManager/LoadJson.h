#pragma once
#include "Model.h"
#include "Validation.h"

class LoadJson
{
public:
	static bool LoadJsonFlights(List<std::shared_ptr<Flight>>*, std::string);

	static bool LoadJsonFillData(List<std::shared_ptr<Flight>>*, Flight*, std::vector<std::string>, std::string, std::string);
};

