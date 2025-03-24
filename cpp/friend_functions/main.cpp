#include "./headers/dynArray.hpp"
#include "./headers/lifeEasier.hpp"
#include "./headers/sort.hpp"
#include <vector>

using std::vector;

class A {
private:
	vector<int> x = { 5, 6, 7 };

	friend void AddTo_x(int& value);
};

class B {
private:
	int a;
public:
	void Set_a(int& value) {
		a = value;
	}
};

void AddTo_x(A& value) {
	x.push_back(value);
}

int main() {
	A abra;
	B cadabra;

	int some_value = 75;
	cadabra.Set_a(some_value);


}