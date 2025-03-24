#include "./headers/lifeEasier.hpp"

class Point {
public:
	//double getPoint() {
	//	double* point = new double[3] {x, y, z};

	//	return point;
	//}
	auto getSumFields() {
		auto a = x + y + z;
		return a;
	}
	double setPoint(double value, double value1, double value2) {
		x = value; y = value1; z = value2;
		return 0;
	}

private:
	double x, y, z;
};

class IDK {
	string sigma = "sigma boy";
	int chapter;
public:
	void yes() {
		print << sigma << chapter;
	}
};
class pract2 {
protected:
	int angryCola = 2;
};
class cola : pract2 {
public:
	void printInfo() {
		print << angryCola;
	}
};

class Hero {
protected:
	int Health;
	int Armour;
	void setParams(int val1, int val2) {
		Health = val1;
		Armour = val2;
	}
};

class Pudge : Hero {
public:
	setParams(20, 15);
	void FreshMeat() {
		Health += 5, Armour += 2;
	}
	void printPudge() {
		print << Health << tab << Armour;
	}
};