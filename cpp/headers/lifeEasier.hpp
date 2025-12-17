#pragma once
#include <array>
#include <iostream>
#include <string>
#define cout std::cout
// #include <cout>
#include <vector>
#define scan std::cin
#define chr char
constexpr char e = '\n';
constexpr char tab = '\t';
using std::string, std::vector;

inline chr Horizontal_separator() { // │
  return char(179);
}
inline chr Vertical_separator() { // ─
  return char(196);
}

void PrintArr(vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << "\t";
  }
  cout << "\n";
}

// inline void separator(int n, chr symbol) {
//   cout << e;
//   for (int i{0}; i <= n; i++) {
//     cout << symbol;
//   }
//   cout << e;
// }
