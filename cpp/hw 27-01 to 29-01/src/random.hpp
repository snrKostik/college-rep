#include "../lib/lifeEasier.hpp"
// #include <cstdlib>
#include "../lib/dynArray.hpp"
#include <random>
#include <string>
// #include "Windows.h"
dynArr da;

inline int generateNumber() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(1, 13);

  return distrib(gen);
}

inline string generateMast() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(0, 3);

  int Mast = distrib(gen);
  switch (Mast) {
  case 0:
    return "\u2665";
  case 1:
    return "\u2666";
  case 2:
    return "\u2663";
  case 3:
    return "\u2660";
  }

  return "";
}

string *cardsCached = da.initStr(53);
int counter = 0;
inline void cache(string concatenated) {
  cardsCached[counter] = concatenated;
  counter++;
}

int countEl = 0;
inline bool isCached(string concatenated) {
  string *a{&concatenated};
  int counter1;
  for (int i{0}; i < 54; i++) {
    counter1 = 0;
    for (int j{0}; j < 54; j++) {
      if (a[i] == cardsCached[j]) {
        counter1++;
      }
    }
  }
  if (counter1 == 0) {
    // print << "Я тупая мразь";
    // da.insertElStr(cardsCached, 54, counter, concatenated);
    countEl++;
    print << countEl << ".\t" << concatenated << e;

    cache(concatenated);
    return true;
  } else {
    return false;
  }
}

inline void generateCards() {
  for (int i{1}; i < 53; i++) {
    int generatedNum = generateNumber();
    string concatenated = "";
    string generatedMast = generateMast();

    if (generatedNum == 1) {
      concatenated = "Туз" + generatedMast;
    } else if (generatedNum == 11) {
      concatenated = "Валет" + generatedMast;
    } else if (generatedNum == 12) {
      concatenated = "Дама" + generatedMast;
    } else if (generatedNum == 13) {
      concatenated = "Король" + generatedMast;
    } else {
      concatenated = std::to_string(generatedNum) + generatedMast;
    }

    // isCached(concatenated);
    if (!isCached(concatenated)) {
      // generateCards();
      i--;
    }

    // scan.get();
    // print << i << ".\t" << cardsCached[i - 1] << e;
  }
  print << "Карты кончились!\n";
}