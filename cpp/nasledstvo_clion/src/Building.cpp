#include "../head/Building.h"

#include "../head/Menu.h"

Building::Building()
{
	address_ = "Paper street";
	square_ = 1.0;
	ID++;
	print << e << Log << "dflt cnstrctr for " << this << " hs bn smmnd" << Clr;
}
Building::Building( const string &address, double square )
{
	address_ = address;
	square_ = square;
	ID++;
	print << e << Log << "spcl cnstrctr for " << this << " hs bn smmnd" << Clr;
}
Building::~Building() { print << e << Log << "dstrctr for " << this << " hs bn smmnd" << Clr; }

void Building::PrintInfo() { printf( template_.c_str(), ID_, address_.c_str(), square_, type_.c_str() ); }
void Building::PrintInfo( string type ) { printf( template_.c_str(), ID_, address_.c_str(), square_, type.c_str() ); }

void Building::setAddress( const string address ) { address_ = address; }
void Building::setSquare( const double square ) { square_ = square; }

inline string Building::getAddress() { return address_; }
inline double Building::getSquare() { return square_; }
inline string Building::getType() { return type_; }
inline int Building::getID(){ return ID_; }