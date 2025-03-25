#include "../../../../.mylibs/lifeEasier.hpp"

class Animal {
private:
  string name = "-";
  int weight = 0;

public:
  void Print() { print << "name: " << name << " weight: " << weight << e; }

protected:
  string a = "asdf";
};

class Cat : public Animal {};

class Dog : public Animal {};

int main() {
  Animal animal;
  Cat cat;
  Dog dog;

  animal.Print();
  cat.Print();
  dog.Print();
}