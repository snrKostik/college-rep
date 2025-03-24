#include "../head/Garage.h"

#include "../head/Building.h"

int Garage::GetCarAmount() const { return carsAmount_; }

Garage::Garage()
{
	carsAmount_ = 0;
	ID++;
}
Garage::Garage( const string &address, double square, int carsAmount ) : Building( address, square )
{
	carsAmount_ = carsAmount;
	ID++;
}

void Garage::PrintInfo()
{
	Building::PrintInfo( type_ );
	printf( "\nCar Amount:\t %i", GetCarAmount() );
}

void Garage::SetCarAmount( int carsAmount ) { carsAmount_ = carsAmount; }
