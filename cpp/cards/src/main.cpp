#include "../lib/lifeEasier.hpp"
#include "../lib/dynArray.hpp"
#include "../src/random.hpp"
#include <clocale>
#include <cstdlib>
#include "Windows.h"

int main() {
	SetConsoleCP(CP_UTF8);
  SetConsoleOutputCP(CP_UTF8);
	setlocale(LC_ALL, "Russian");
  print << "Никол" << e;

	DynamicArrayStr cardsArr(53);
	for (int i{ 0 }; i < 16; i++){
		print << generateMast();
	}
	print << u8"♥♦♣♠";
}