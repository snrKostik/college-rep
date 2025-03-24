#pragma once

#include "./headers/lifeEasier.hpp"
#include "Building.h"

class Garage :
	public Building
{
private:
	int carsAmount;
	string type = "Garage";
public:
	int GetCarAmount();
};

extern Garage carsAmount;