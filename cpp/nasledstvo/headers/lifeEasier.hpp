#pragma once
// It's mine header file which I use for increasing readability in code
#include <array>
#include <iostream>
#include <string>
#define prnt std::cout
#define scan std::cin
#define chr char
constexpr char e = '\n';
constexpr char tab = '\t';
using std::string;

//string logStart = "\033[38;5;237m";
//string logEnd = "\033[m";

inline chr Horizontal_separator() { // │
	return char(179);
}
inline chr Vertical_separator() { // ─
	return char(196);
}

inline void separator(int n, chr symbol) {
	prnt << e;
	for (int i{ 0 }; i <= n; i++) {
		prnt << symbol;
	}
	prnt << e;
}