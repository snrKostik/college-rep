#include "Building.h"

Building::Building() {
	adress_ = "Paper street";
	square_ = 20.0;
	ID++;
}
Building::Building(
	string adressValue,
	double squareValue
) {
	adress_ = adressValue;
	square_ = squareValue;
	ID++;
}
Building::~Building() {
	prnt << "\033[38;5;237mdstrctr for " << this << " has been smmnd\033[m\n";
}

//void Building::PrintInfo()
//{
//}

void Building::PrintInfo() {
	printf("Adress:\t\t %s\nType:\t\t %s\nSquare:\t\t %.2f\nID:\t\t %i\n",
		adress_.c_str(), this->type_.c_str(), square_, ID_);
}
