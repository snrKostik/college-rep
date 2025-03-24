#pragma once
#include "../headers/lifeEasier.hpp"
//#include

class dynArr {
public:
	inline int* init(int size) {
		int* arr = new int[size];

		for (int i{ 0 }; i < size; i++)
			arr[i] = 0;

		return arr;
	}

	inline string* initStr(int size) {
		string* arr = new string[size];

		for (int i{ 0 }; i < size; i++)
			arr[i] = "0";

		return arr;
	}

	inline int* initRandom(int size) {
		int* arr = new int[size];
		setRandSeed(0);
		for (int i{ 0 }; i < size; i++) {
			arr[i] = rand() % 9 + 1;
		}
		return arr;
	}

	inline void out(int* arr, int size) {
		for (int i{ 0 }; i < size; i++)
			print << arr[i] << " ";
		print << e;
	}

	inline int* copy(int* original, int size) {
		int* copyedArr = new int[size];

		for (int i{ 0 }; i < size; i++) {
			copyedArr[i] = original[i];
		}
		return copyedArr;
	}

	inline string* copy(string* original, int size) {
		string* copyedArr = new string[size];

		for (int i{ 0 }; i < size; i++) {
			copyedArr[i] = original[i];
		}
		return copyedArr;
	}

	inline int* insertEl(int* arr, int size, int el, int insert) {
		for (int i{ 0 }; i < size; i++) {
			if (i == el)
				arr[i] = insert;
		}
		return arr;
	}

	inline string* insertEl(string* arr, int size, int el, string insert) {
		for (int i{ 0 }; i < size; i++) {
			if (i == el)
				arr[i] = insert;
		}
		return arr;
	}

	inline void delArr(int* arr) {
		delete arr;
	}

	inline void delEl(int* arr, int size, int el) {
		for (int i{ 0 }; i < size; i++) {
			if (i == el)
				arr[i] = 0;
		}
	}

	inline void delRange(int* arr, int size, int first, int last) {
		for (int i{ 0 }; i < size; i++) {
			if (arr[i] >= arr[first] && arr[i] <= arr[last])
				delEl(arr, size, i);
		}
	}
private:
	inline void setRandSeed(int seed) {
		srand(seed);
	}
};