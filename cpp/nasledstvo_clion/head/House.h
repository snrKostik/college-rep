#ifndef HOUSE_H
#define HOUSE_H

#include "Building.h"
#include "D:/.mylibs/lifeEasier.hpp"

class House : public Building
{
 private:
	int apartmentAmount_;
	string type_ = "House";

 public:
	House();
	House( const string &address_, double square_, int apartmentAmount );
	void PrintInfo() override;
	void ApartmentAmountMessage();

	int GetApartmentAmount();
	void SetApartmentAmount( int apartmentAmount );
};

extern House apartmentAmount;

#endif	// HOUSE_H
