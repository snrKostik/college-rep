#pragma once
#include "../lib/lifeEasier.hpp"

class sort {
public:
	inline int* bubble(int* array, int size) {
		for (int i{ 0 }; i < size; i++) {
			for (int j{ 0 }; j < size - i; j++) {
				if (array[j] < array[j - 1]) {
					int temp = array[j];
					array[j] = array[j - 1];
					array[j - 1] = temp;
				} // if
			} // for j
		}// for i
		return array;
	}
	inline string* bubble(string* array, int size) {
		for (int i{ 0 }; i < size; i++) {
			for (int j{ 0 }; j < size - i; j++) {
				if (array[j] < array[j - 1]) {
					string temp = array[j];
					array[j] = array[j - 1];
					array[j - 1] = temp;
				} // if
			} // for j
		}// for i
		return array;
	}
private:
};