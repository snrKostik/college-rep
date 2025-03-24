#include "../head/House.h"
#include "../head/Building.h"

int House::GetApartmentAmount() { return apartmentAmount_; }

House::House() : Building()
{
	apartmentAmount_ = 1;
	ID++;
}

House::House( const string &address_, double square_, int apartmentAmount ) : Building( address_, square_ )
{
	apartmentAmount_ = apartmentAmount;
	ID++;
}

void House::ApartmentAmountMessage() { printf( "\nApartment amount:%i", GetApartmentAmount() ); }

void House::PrintInfo()
{
	Building::PrintInfo( type_ );
	ApartmentAmountMessage();
}

void House::SetApartmentAmount( int apartmentAmount ) { apartmentAmount_ = apartmentAmount; }
