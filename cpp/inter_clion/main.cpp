#include "./include/consonant.hpp"
#include "./include/vovel.hpp"
#include "../../../../.mylibs/lifeEasier.hpp"
// #include "../include\interface.hpp"

int main() {
  Consonant ConsAn;
  Vovel VovAn;
  static string test = "abcdefghijklmnopqrstuvwxyz";
  int consonants = 0;
  int vovels = 0;
  consonants = ConsAn.analyse(test);
  vovels = VovAn.analyse(test);

  print << test << "\nThis string has\n"
        << consonants << "\tConsonants\n"
        << vovels << "\tVovels\n";
}