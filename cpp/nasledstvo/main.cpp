#include "./headers/dynArray.hpp"
#include "./headers/lifeEasier.hpp"
#include "./headers/sort.hpp"
#include "Apartment.h"
#include "Building.h"
#include "Garage.h"
#include "House.h"
//#include <locale>

//! >= 1 string && >= 1 int
//! ��� ������ ����� ��������
//! 
//! ����� ������������ ������, ���������
//! 
//! ���������� ���������� ���������, ��������, ����������
//! 
//! ����
//! 0. ����� (���������� ������)
//! 1. �������� �������
//! 2. ������� ������� �� �������
//! 3. ����� ��������� � �������
//! 4. ��������� �� ��������� � ���� ���������
//! 
//! ����������, ���, �����, �������� - �������� ���� �������

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");


	Building abeb;
	Building asss("�������, 10", 90.646);
	Building asdss("������, 15", 190.679);

	abeb.PrintInfo();
	prnt << e;
	asss.PrintInfo();
	prnt << e;
	asdss.PrintInfo();

	//prnt << "b";
	House leto("������, 60", 43.123456, 80);
	//prnt << "a";
	prnt << e;
	leto.PrintInfo();
}