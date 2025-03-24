#include "./headers/dynArray.hpp"
#include "./headers/lifeEasier.hpp"
#include "./headers/sort.hpp"

//! Здесь нет второго задания

dynArr da;
int* mergeArr(int* arr1, int size1, int* arr2, int size2) {
	int mergedSize = size1 + size2;
	int* mergedArr = da.init(mergedSize);

	for (int i{ 0 }; i < size1; i++) {
		da.insertEl(mergedArr, size1, i, arr1[i]);
	}
	for (int j{ size1 }; j < mergedSize; j++) {
		da.insertEl(mergedArr, mergedSize, j, arr2[j - size1]);
	}

	return mergedArr;
}

int main() {
	sort sort;

	srand(15632);
	int* randArr1 = da.initRandom(10);
	srand(100);
	int* randArr2 = da.initRandom(10);

	//da.out(randArr1, 10);
	//print << e;
	//da.out(randArr2, 10);
	//print << e;

	int* merged = mergeArr(randArr1, 10, randArr2, 10);
	da.out(merged, 20);
}