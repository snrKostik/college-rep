#include "./headers/dynArray.hpp"
#include "./headers/lifeEasier.hpp"
#include "./headers/sort.hpp"

//! Здесь нет второго задания
bool isSymmetric(int** matrix, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i != j && matrix[i][j] != matrix[j][i]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	dynArr da;
	int size;

	print << "size of matrix: ";
	scan >> size;

	int** matrix = new int* [size];
	for (int i = 0; i < size; i++) {
		matrix[i] = da.init(size);
	}

	print << "Enter its elements:\n";
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			scan >> matrix[i][j];
		}
	}

	for (int i = 0; i < size; i++) {
		da.out(matrix[i], size);
	}


	if (isSymmetric(matrix, size)) {
		print << "symmetric\n";
	}
	else {
		print << "not symmetric\n";
	}

	for (int i = 0; i < size; i++) {
		da.delArr(matrix[i]);
	}
	delete[] matrix;

	return 0;
}

/*
1 2 3
2 1 2
3 2 1

*/