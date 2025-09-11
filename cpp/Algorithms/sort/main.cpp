#include <cstdlib>
#include <ctime>
#include <print>
#include <random>
#include <vector>

#include "./find.hpp"
#include "./sort.hpp"

vector<int> InitRandomArr(vector<int> arr) {
  srand(1000);
  for (int i{0}; i < 1000; ++i) {
    arr.at(i) = rand() % 1000;
  }
  return arr;
}

int main() {
  vector<int> array(1000, 0);
  array = InitRandomArr(array);

  Sort(array);
  Find();

  println("\n\n\nfinish");
}
