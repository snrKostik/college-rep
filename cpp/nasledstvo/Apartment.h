#pragma once

#include "./headers/lifeEasier.hpp"
#include "House.h"

class Apartment :
	public House
{
private:
	int apartmentNumber;
	int floor;
	string type = "Apartment";
public:
	int GetApartmentNumber();
};

extern Apartment apartmentNumber;