#include "../../../../../.mylibs/lifeEasier.hpp"
#include <exception>
#include <iostream>
#include <stdexcept>

void Foo() {
  int n1, n2, answer;
  print << "Введи 2 числа" << e;
  scan >> n1;
  string typeError =
      "Как насчет того, чтобы ввести число, а не какую-то *****?!";
  if (typeid(n1).name() != "i")
    throw std::invalid_argument(typeError);
  scan >> n2;
  if (typeid(n2).name() != "i")
    throw std::invalid_argument(typeError);
  if (n2 == 0)
    throw std::runtime_error(":( Вселенная только что схлопнулась...");
  answer = n1 / n2;
  print << "Операция прошла успешно. Ответ = " << answer;
}

int main() {
  try {
    Foo();
  } catch (std::runtime_error &ee) {
    print << ee.what() << e;
  } catch (std::invalid_argument &ee) {
    print << ee.what() << e;
  } catch (...) {
    print << "Что-то пошло не так и я не знаю как это исправить" << e;
  }
}