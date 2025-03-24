#include "../include\consonant.hpp"
#include "../include\interface.hpp"

int Consonant::analyse(string str) {
  static chr consonants[21]{'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm',
                     'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
  for (int character = 0; character < str.length(); character++) {
    for (char consonant : consonants) {
      if (str[character] == consonant) {
        charCount++;
      }
    }
  }
  return charCount;
}