#include "../../../../.mylibs/lifeEasier.hpp"
#include <cstddef>
#include <string>
#include ""

class Point {
private:
  int _x = 0;
  int _y = 0;
  int _z = 0;

public:
  Point(int x, int y, int z) : _x(x), _y(y), _z(z) {}

  bool operator==(const Point &point) const {
    return (_x == point._x and _y == point._y and _z == point._z);
  }

  Point operator-(const Point &point) const {
    return Point{_x - point._x, _y - point._y, _z - point._z};
  }

  Point &operator++() {
    _x++;
    _y++;
    _z++;
    return *this;
  }

  Point operator++(int) {
    Point temp = *this;
    ++(*this);
    return temp;
  }

  string getPoint() {
    string point = to_string(_x) + " " + to_string(_y) + " " + to_string(_z);
    return point;
  }
};

int main() {
  Point p1(1, 2, 3);
  Point p2(1, 2, 3);
  Point p3(4, 5, 6);

  print << "p1 == p2: " << (p1 == p2) << e; // true
  print << "p1 == p3: " << (p1 == p3) << e; // false

  Point p4 = p3 - p1;
  print << "p3 - p1: " << p4.getPoint() << e; // (3, 3, 3)

  Point p5 = p1++;
  print << "p1++: " << p5.getPoint()
        << e; // (1, 2, 3) (значение p1 до инкремента)
  print << "p1 after incr: " << p1.getPoint() << e; // (2, 3, 4)

  Point p6 = ++p2;
  print << "++p2: " << p6.getPoint() << e;          // (2, 3, 4)
  print << "p2 after incr: " << p2.getPoint() << e; // (2, 3, 4)
}