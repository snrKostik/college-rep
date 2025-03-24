#include "./headers/dynArray.hpp"
#include "./headers/lifeEasier.hpp"
#include "./headers/sort.hpp"
#include "Apartment.h"
#include "Building.h"
#include "Garage.h"
#include "House.h"
//#include <locale>

//! >= 1 string && >= 1 int
//! При инпуте нужна проверка
//! 
//! Нужны конструкторы дефолт, параметры
//! 
//! Перегрузка операторов сравнения, сложения, инкремента
//! 
//! Меню
//! 0. Выход (Завершение работы)
//! 1. Добавить элемент
//! 2. Удалить элемент по индексу
//! 3. Вывод элементов в консоль
//! 4. Сравнения на равенство у двух элементов
//! 
//! Сооружение, дом, гараж, квартира - перечень моих классов

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");


	Building abeb;
	Building asss("Пушкина, 10", 90.646);
	Building asdss("Ленина, 15", 190.679);

	abeb.PrintInfo();
	prnt << e;
	asss.PrintInfo();
	prnt << e;
	asdss.PrintInfo();

	//prnt << "b";
	House leto("Летова, 60", 43.123456, 80);
	//prnt << "a";
	prnt << e;
	leto.PrintInfo();
}