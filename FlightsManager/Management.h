#pragma once
#include <string>
#include <vector>
#include <memory>

#include "Model.h"
#include "List.h"

#include "User.h"
#include "LoadYaml.h"
#include "LoadJson.h"
#include "Algorithm.h"

/*G³ówna klasa zawieraj¹ce metody odpowiedzialne za przeprowadzenie ca³ego programu*/
class Management
{
public:
	/*Konstruktor*/
	Management();

	/*Przeprowadzenie programu*/
	bool ManagementManage(std::string);
};

