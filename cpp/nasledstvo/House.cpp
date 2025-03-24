#include "Building.h"
#include "House.h"
#include <cstdio>

int House::GetApartmentAmount()
{
	return 0;
}

int House::GetApproachAmount()
{
	return 0;
}

House::House() : Building() {
	ID++;
	apartmentAmount_ = 0;
}

House::House(
	const string& adress_, double square_,
	int apartmentAmount)
	: Building(adress_, square_)/*,
	apartmentAmount_(apartmentAmount)*/ {
	ID++;
	//adress_ = adress;
	apartmentAmount_ = apartmentAmount;
}

//House::~House() {
//	Building::~Building();
//};

void House::PrintInfo() {
	Building::PrintInfo();
	printf("Apartment amount:%i\n", apartmentAmount_);
}

/*
Building
├House
│└Apartment
└Garage
*/