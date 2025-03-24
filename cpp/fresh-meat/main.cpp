#include "../hpp/lifeEasier.hpp"

class Pudge {
public:
  int Health;
  int Armour;

  Pudge(int initialHealth, int initialArmour)
      : Health(initialHealth), Armour(initialArmour) {}

  void FreshMeat(int value) {
    Health += value;
    Armour += value;
  }
};

int main() {
  ruloc;
  Pudge pudge(100, 5);
  print << "Начальные значения:\n";
  print << "Здоровье: " << pudge.Health << e;
  print << "Броня: " << pudge.Armour << e;

  int meatValue = 10;
  pudge.FreshMeat(meatValue);

  print << "\nПосле использования FreshMeat (+" << meatValue << "):\n";
  print << "Здоровье: " << pudge.Health << e;
  print << "Броня: " << pudge.Armour << e;
}