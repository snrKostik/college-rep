#include "../../../../.mylibs/lifeEasier.hpp"

int main() {
  print << "Enter here vector size: ";
  int vectorSize = 0;
  vectorSize = Scan(vectorSize);

  vector<int> aaa(vectorSize);

  print << "Enter here all vector elements: ";
  for (int i{0}; i < vectorSize; i++) {
    scan >> aaa[i];
  }
  print << "print in other direction: ";
  for (int i{vectorSize - 1}; i >= 0; i--) {
    print << aaa[i] << " ";
  }

  print << "Enter here vector size: ";
  vectorSize = Scan(vectorSize);
  vector<string> vvv(vectorSize);

  print << "Enter here all vector elements: ";
  for (int i{0}; i < vectorSize; i++) {
    scan >> vvv[i];
  }
  vvv[vectorSize + 1] = "3";
}