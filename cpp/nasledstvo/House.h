#pragma once

#include "./headers/lifeEasier.hpp"
#include "Building.h"

class House : public Building
{
private:
	//int apartmentAmount;
protected:
	int apartmentAmount_;
	string type_ = "House";
public:
	House();
	House(const string& adress, double square, int apartmentAmount);
	//~House();

	void PrintInfo() override;
	int GetApartmentAmount();
	int GetApproachAmount();
	//void PrintInfo();
};

extern House apartmentAmount, approachAmount;