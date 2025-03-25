#include "../hpp/lifeEasier.hpp"
#include <cstdlib>
// #include <random>
// #include <string>

class Pudge {
  int Health;
  int Armour;
  string *abilities = new string[5]{"I ", "Am ", "Not ", "A ", "Doter "};

public:
  Pudge(int initialHealth, int initialArmour) {
    Health = initialHealth;
    Armour = initialArmour;
  }
  ~Pudge() { delete[] abilities; }

  int getHP() { return Health; }
  int getArmour() { return Armour; }

  void FreshMeat(int value) {
    Health += value;
    Armour += value;
  }

  string getAbility() {
    int n = std::rand() % 10;
    if (n > 4)
      n -= 5;
    return abilities[n] + e;
  }

  int DamageAmount(int level) {
    int answer = 8;
    if (level < 50)
      answer = answer * 1.1 + level / 1.5;
    else
      answer = answer * 1.4 + level / 3;

    return answer;
  }
};

int main() {
  Pudge pudge(100, 5);
  print << "Начальные значения:\n";
  print << "Здоровье: " << pudge.getHP() << e;
  print << "Броня: " << pudge.getArmour() << e;

  int meatValue = 10;
  pudge.FreshMeat(meatValue);

  print << "\nПосле использования FreshMeat (+" << meatValue << "):\n";
  print << "Здоровье: " << pudge.getHP() << e;
  print << "Броня: " << pudge.getArmour() << e;

  print << pudge.getAbility();

  print << pudge.DamageAmount(5) << e;
  print << pudge.DamageAmount(500) << e;
}