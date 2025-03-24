#pragma once
// It's mine header file which I use for increasing readability in code
#include <array>
#include <vector>
#include <iostream>
#include <string>
#define print std::cout
#define scan std::cin
#define chr char
constexpr char e = '\n';
constexpr char tab = '\t';
using std::string;
using std::vector;

inline chr Horizontal_separator() { // │
	return char(179);
}
inline chr Vertical_separator() { // ─
	return char(196);
}

inline void separator(int n, chr symbol) {
	print << e;
	for (int i{ 0 }; i <= n; i++) {
		print << symbol;
	}
	print << e;
}