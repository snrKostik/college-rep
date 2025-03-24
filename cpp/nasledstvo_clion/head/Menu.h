#ifndef MENU_H
#define MENU_H
#pragma once
#include "D:/.mylibs/lifeEasier.hpp"

static int ID = 0;

namespace Menu
{
	void Print();
	chr GetChoice();
	void AddElement();
	void DeleteByID();
	void PrintAll();
	void Compare(int a, int b);
	void compareAttribute(const string& attributeName, int value1, int value2);
	void compareAttribute(const string& attributeName, const string& value1, const string& value2);
	void compareAttribute(const string& attributeName, double value1, double value2);
}

#endif //MENU_H
