#include "./headers/lifeEasier.hpp"
#include "windows.h"
#include <limits>

using std::to_string; using std::numeric_limits; using std::streamsize; using std::max;

static int arraySize = 0;

class Drink {
private:
	int ID;
	int popularity;
	int price;
	int tastyness;
	bool isAlco;
	bool isCold;
	string name;
	string ingredients;
public:
	Drink() { // Default
		ID = 0;
		popularity = 0;
		price = 0;
		tastyness = 0;
		isAlco = false;
		isCold = false;
		name = "-";
		ingredients = "-";
	}
	Drink(
		int IDValue,
		int popularityValue,
		double priceValue,
		int tastynessValue,
		bool isAlcoValue,
		bool isColdValue,
		string nameValue,
		string ingredientsValue)
	{
		ID = IDValue;
		popularity = popularityValue;
		price = priceValue;
		tastyness = tastynessValue;
		isAlco = isAlcoValue;
		isCold = isColdValue;
		name = nameValue;
		ingredients = ingredientsValue;
	}
	~Drink() {
		print << "\033[38;5;237mDestructor has been summoned: " << ID << " " << name << "\033[m\n";
	}

	inline int getPopularity() { return popularity; }
	inline double getPrice() { return price; }
	inline int getTastyness() { return tastyness; }
	inline bool getIsAlco() { return isAlco; }
	inline bool getIsCold() { return isCold; }
	inline string getName() { return name; }
	inline string getIngredients() { return ingredients; }

	inline string getAllInfo() {
		string info = "ID:\t\t" + to_string(ID);
		info.append("\nPopularity:\t" + to_string(popularity));
		info.append("\nPrice:\t\t" + to_string(price));
		info.append("\nTastyness:\t" + to_string(tastyness));
		info.append("\nAlco?:\t\t" + to_string(isAlco));
		info.append("\nCold?:\t\t" + to_string(isCold));
		info.append("\nName:\t\t" + name);
		info.append("\nIngredients:\t" + ingredients);
		return info;
	}

	static Drink* addToArray(Drink object, Drink* arr) {
		Drink* newArr = new Drink[arraySize + 1];
		for (int i = 0; i < arraySize; i++) {
			newArr[i] = arr[i];
		}
		newArr[arraySize] = object;
		arraySize++;
		if (arr != nullptr) delete[] arr;
		return newArr;
	}


	static int isScanFailINT(int input) {
		scan >> input;
		while (scan.fail()) {
			scan.clear();
			scan.ignore(65536, e);
			scan >> input;
		}
		return input;
	}
	static string isScanFailSTRING(string input) {
		scan >> input;
		return input;
	}
	static bool isScanFailBOOL(bool input) {
		scan >> input;
		while (scan.fail() || !(input >= 0 && input <= 1)) {
			scan.clear();
			scan.ignore(6500, e);
			scan >> input;
		}
		return input;
	}

	static Drink* addDrink(Drink* arr) {
		int choice;
		print << "Empty/Full (0/1): ";
		scan >> choice;

		if (choice == 0) {
			Drink obj;
			return addToArray(obj, arr);
		}
		else {
			int ID = 0;
			int popularity = 0;
			int price = 0;
			int tastyness = 0;
			bool isAlco = 0;
			bool isCold = 0;
			string name = "";
			string ingr = "";

			string stopper;

			print << "ID: ";
			ID = isScanFailINT(ID);

			print << "popularity: ";
			popularity = isScanFailINT(popularity);

			print << "price: ";
			price = isScanFailINT(price);

			print << "tastyness: ";
			tastyness = isScanFailINT(tastyness);

			print << "is alco?: ";
			isAlco = isScanFailBOOL(isAlco);

			print << "is cold?: ";
			isCold = isScanFailBOOL(isCold);

			print << "name: ";
			name = isScanFailSTRING(name);

			print << "ingredients: ";
			ingr = isScanFailSTRING(ingr);

			Drink obj(ID, popularity, price, tastyness, isAlco, isCold, name, ingr);
			return addToArray(obj, arr);
		}
	}


	static Drink* BubbleSort(Drink* arr, int choice) {
		print << "\033[38;5;235mSorting...\033[m\n";
		switch (choice) {
		case 4:
			for (int i = 0; i < arraySize - 1; i++) {
				for (int j = 1; j < arraySize - i; j++) {
					if (arr[j].getPrice() < arr[j - 1].getPrice()) {
						Drink temp = arr[j];
						arr[j] = arr[j - 1];
						arr[j - 1] = temp;
					}
				}
			}
			break;
		case 5:
			for (int i = 0; i < arraySize - 1; i++) {
				for (int j = 1; j < arraySize - i; j++) {
					if (arr[j].getName() < arr[j - 1].getName()) {
						Drink temp = arr[j];
						arr[j] = arr[j - 1];
						arr[j - 1] = temp;
					}
				}
			}
			break;
		case 6:
			for (int i = 0; i < arraySize - 1; i++) {
				for (int j = 1; j < arraySize - i; j++) {
					if (arr[j].getPopularity() < arr[j - 1].getPopularity()) {
						Drink temp = arr[j];
						arr[j] = arr[j - 1];
						arr[j - 1] = temp;
					}
				}
			}
			break;
		case 7:
			for (int i = 0; i < arraySize - 1; i++) {
				for (int j = 1; j < arraySize - i; j++) {
					if (arr[j].getTastyness() < arr[j - 1].getTastyness()) {
						Drink temp = arr[j];
						arr[j] = arr[j - 1];
						arr[j - 1] = temp;
					}
				}
			}
			break;
		}
		return arr;
	}

	static void outputAll(Drink* object) {
		print << e;
		for (int i = 0; i < arraySize; i++) {
			print << object[i].getAllInfo() << e;
			separator(80, Vertical_separator());
			print << e;
		}
	}

	static Drink* Menu(Drink* arr) {
		int choice = -654;
		while (choice != 0) {
			print <<
				"1. Add object\n" <<
				"Sort by:\n\t4. Price\n\t5. Name\n\t6. Popularity\n\t7. Tastyness\n" <<
				"2. Print all\n" <<
				//"3. Set values (WIP)\n" <<
				"0. Exit\n" <<
				"Enter your choice: ";
			scan >> choice;

			switch (choice) {
			case 0:
				break;
			case 1:
				arr = addDrink(arr);
				break;
			case 4:
			case 5:
			case 6:
			case 7:
				arr = BubbleSort(arr, choice);
				break;
			case 2:
				outputAll(arr);
				break;
			case 3:

				break;
			default:

				break;
			}
		}
		return arr;
	}
};
