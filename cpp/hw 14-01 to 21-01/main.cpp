#include "./headers/dynArray.hpp"
#include "./headers/lifeEasier.hpp"
#include "./headers/sort.hpp"

int main() {
	dynArr da;
	sort sort;
	int* randArr = da.initRandom(10);
	sort.bubble(randArr, 10);
	da.out(randArr, 10);
}