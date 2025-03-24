#ifndef BUILDING_H
#define BUILDING_H

#include "D:/.mylibs/lifeEasier.hpp"
#include "Menu.h"
#include <iomanip>

class Building
{
 private:
	string template_ = "\nID:\t\t %i\nAddress:\t %s\nSquare:\t\t %.2f\nType:\t\t %s";
	string address_;
	double square_;
	int ID_ = ID;
	string type_ = "Building";

 public:
	Building();
	Building( const string &address, double square );
	virtual ~Building();
	virtual void PrintInfo();
	virtual void PrintInfo( string type );

	virtual void setAddress( string address );
	virtual void setSquare( double square );
	virtual string getAddress();
	virtual double getSquare();
	virtual string getType();
	virtual int getID();
};

#endif	// BUILDING_H
