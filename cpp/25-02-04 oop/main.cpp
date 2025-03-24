#include "./headers/dynArray.hpp"
#include "./headers/lifeEasier.hpp"
#include "./headers/sort.hpp"
#include "Point.hpp"

int main() {
	Point playerSpawn;
	playerSpawn.setPoint(0, 63, 5);
	//print << playerSpawn.x << tab << playerSpawn.y << tab << playerSpawn.z;
	//print << playerSpawn.getPoint();

	//────────────────────────────────────

	print << e;
	Point Void;

	try
	{
		//print << Void.getPoint();
	}
	catch (const std::exception&)
	{
		print << "You NEED to initialize all fields!";//! Этот блок кода не работает
	}

	print << e << playerSpawn.getSumFields();
	print << e << Void.getSumFields();

	//────────────────────────────────────

	print << "\n\n";

	IDK kdi;
	kdi.yes();


	Pudge Inokentiy;
	print << "\n\n\n";
	Inokentiy.printPudge();
	Inokentiy.FreshMeat();
	print << "\n\n\n";
	Inokentiy.printPudge();
}