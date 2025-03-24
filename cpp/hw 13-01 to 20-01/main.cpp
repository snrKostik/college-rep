#include "./headers/dynArray.hpp"
#include "./headers/lifeEasier.hpp"
#include "./headers/sort.hpp"

int main() {
	dynArr da;
	sort sort;
	int size = 10;
	int* dyn = da.initRandom(size);

	sort.bubble(dyn, size);

	da.out(dyn, size);

	double sumOfAll = 0;
	for (int i{ 0 }; i < size; i++) {
		sumOfAll += dyn[i];
	}
	double avg = sumOfAll / size;
	print << avg;
}