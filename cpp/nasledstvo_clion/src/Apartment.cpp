#include "../head/Apartment.h"

#include "../head/Building.h"
#include "../head/House.h"

int Apartment::GetApartmentNumber() const { return apartmentNumber_; }

Apartment::Apartment() : Building()
{
	apartmentNumber_ = 1;
	ID++;
}

Apartment::Apartment( const string &address, double square, int apartmentNumber/*, int floor */) :
		Building( address, square )
{
	apartmentNumber_ = apartmentNumber;
	ID++;
}

void Apartment::PrintInfo()
{
	Building::PrintInfo( type_ );
	printf( "\nNumber:\t\t %i", apartmentNumber_ );
}

void Apartment::SetApartmentNumber( int apartmentNumber ) { apartmentNumber_ = apartmentNumber; }