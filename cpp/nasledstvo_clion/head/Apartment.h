#ifndef APARTMENT_H
#define APARTMENT_H

#include "D:/.mylibs/lifeEasier.hpp"
#include "House.h"

class Apartment : public Building
{
 private:
	int apartmentNumber_;
	string type_ = "Apartment";

 public:
	Apartment();
	Apartment( const string& address, double square, int apartmentNumber );
	void PrintInfo() override;

	int GetApartmentNumber() const;
	void SetApartmentNumber( int apartmentNumber );
};

extern Apartment apartmentNumber;

#endif	// APARTMENT_H
