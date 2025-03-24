#include <clocale>
#include <locale>
#include "D:/.mylibs/lifeEasier.hpp"
#include "head/Building.h"
#include "head/Menu.h"

int main()
{
	chr _choice;
	do
	{
		Menu::Print();
		_choice = Menu::GetChoice();
	} while ( _choice != '9' );
}
