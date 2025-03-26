#include "../../../../.mylibs/lifeEasier.hpp"

static int Army_health = 0;
static int Боевая_мощь = 0;
class Coo {
private:
  int health = 0;
  int damage = 0;

public:
  Coo(int _health, int _damage) {
    health = _health;
    damage = _damage;
    Army_health += health;
    Боевая_мощь += damage;
  }
  ~Coo() {}

  inline void setHealth(int _health) { health = _health; }
  inline int getHealth() { return health; }

  inline void setDamage(int _damage) { damage = _damage; }
  inline int getDamage() { return damage; }

  inline int getArmy_health() { return Army_health; }
  inline int getБоевая_мощь() { return Боевая_мощь; }
};

int main() {
  Coo soldier1(50, 25);
  Coo soldier2(50, 25);
  Coo soldier3(50, 25);
  Coo soldier4(50, 25);
  Coo shtab(0, 0);
  print << shtab.getArmy_health() << e << shtab.getБоевая_мощь();
}