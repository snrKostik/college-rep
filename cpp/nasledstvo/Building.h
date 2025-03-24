#pragma once
#include "headers/lifeEasier.hpp"

static int ID = 0;

class Building
{
protected:
	string adress_;
	string type_ = "Building";
	double square_;
	int ID_ = ID;
public:
	Building();
	Building(string adress, double square);
	virtual ~Building();
	virtual void PrintInfo();
};

//extern Building adress, population, floorAmount, square;