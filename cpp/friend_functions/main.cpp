#include "../../../../.mylibs/lifeEasier.hpp"
class ClassB;

class ClassA {
private:
  int a, b;

public:
  ClassA(int x, int y) : a(x), b(y) {}
  friend int sumFields(const ClassA &objA, const ClassB &objB);
};

class ClassB {
private:
  int c, d;

public:
  ClassB(int x, int y) : c(x), d(y) {}
  friend int sumFields(const ClassA &objA, const ClassB &objB);
};

int sumFields(const ClassA &objA, const ClassB &objB) {
  return objA.a + objA.b + objB.c + objB.d;
}

int main() {
  ClassA objA(3, 5);
  ClassB objB(7, 2);

  std::cout << "Сумма всех полей: " << sumFields(objA, objB) << std::endl;
  return 0;
}
