#ifndef GARAGE_H
#define GARAGE_H

#include "Building.h"
#include "D:/.mylibs/lifeEasier.hpp"

class Garage : public Building
{
 private:
	int carsAmount_;
	string type_ = "Garage";

 public:
	Garage();
	Garage( const string &address, double square, int carsAmount );
	void PrintInfo() override;

	int GetCarAmount() const;
	void SetCarAmount( int carsAmount );
};

extern Garage carsAmount;

#endif	// GARAGE_H
