#include "./Drink.hpp"
//#include "./headers/dynarray.hpp"
#include "./headers/lifeEasier.hpp"
//#include "./headers/sort.hpp"

//class aaaaaa {
//private:
	//int balbla = Drink::getArraySize();
//};

int main() {
	//Drink helper;
	Drink coffee(1, 75, 250.75, 100, false, false, "Coffee(Espresso)", "Coffee, water, sugar(optional)");
	Drink water(2, 100, 30.5, 50, false, true, "Water", "Two pieces of hydrogen and one piece of oxygen");
	Drink blood(3, 1, 2500.99, -50, false, false, "Human blood", "-");
	//Drink cola;
	//std::cout << cola.test;

	Drink* helper = nullptr;
	helper = Drink::addToArray(coffee, helper);
	helper = Drink::addToArray(blood, helper);
	helper = Drink::addToArray(water, helper);

	//helper->addToArray(coffee, helper);

	helper = Drink::Menu(helper);

	//Drink::outputAll(helper);

	delete[] helper;
	return 0;
}