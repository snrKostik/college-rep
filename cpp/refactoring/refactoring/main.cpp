#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	vector< string> names;
	vector<int> ages;
	vector< string> emails;
	vector< string> phones;
	int count;

	cout << "сколько людей?";
	cin >> count;
	cin.ignore();

	for (int i = 0; i < count; ++i) {
		string name, email, phone;
		int age;
		cout << "Имя: ";
		getline(cin, name);
		cout << "Возраст: ";
		cin >> age;
		cout << "емейл: ";
		cin >> email;
		cout << "тэлефон: ";
		cin >> phone;
		names.push_back(name);
		ages.push_back(age);
		emails.push_back(email);
		phones.push_back(phone);
		cin.ignore();
	}

	int n = ages.size();
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (ages[j] > ages[j + 1]) {
				swap(ages[j], ages[j + 1]);
				swap(names[j], names[j + 1]);
				swap(emails[j], emails[j + 1]);
				swap(phones[j], phones[j + 1]);
			}
		}
	}

	cout << "имена:\n";
	for (const string& name : names) {
		cout << name << endl;
	}

	string nameToFind;
	cout << "найти:";
	getline(cin, nameToFind);
	for (const string& name : names) {
		if (name == nameToFind) {
			cout << "нашел: " << name << endl;
		}
	}

	int ageThreshold;
	cout << "вв возраст:";
	cin >> ageThreshold;

	for (int i = 0; i < names.size(); ) {
		if (ages[i] > ageThreshold) {
			names.erase(names.begin() + i);
			ages.erase(ages.begin() + i);
			emails.erase(emails.begin() + i);
			phones.erase(phones.begin() + i);
		}
		else {
			++i;
		}
	}

	cout << "Остатки:\n";
	for (size_t i = 0; i < names.size(); ++i) {
		cout << names[i] << " " << ages[i] << endl;
	}

	return 0;
}