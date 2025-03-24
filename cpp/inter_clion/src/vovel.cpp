#include "../include\vovel.hpp"
#include "../include\interface.hpp"
// #include <cstring>

int Vovel::analyse(string str) {
  static chr vovels[5]{'a', 'e', 'i', 'o', 'u'};
  for (int character = 0; character < str.length(); character++) {
    for (char vovel : vovels) {
      if (str[character] == vovel) {
        charCount++;
      }
    }
  }
  return charCount;
}