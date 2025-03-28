#include "../../../../.mylibs/lifeEasier.hpp"
#include <cmath>

class Shape {
protected:
  static int idCounter;
  int id;

public:
  Shape() { id = ++idCounter; }
  virtual ~Shape() { --idCounter; }
  virtual double area() const = 0;
  virtual void show() const = 0;
  int getId() const { return id; }

  bool operator==(const Shape &other) const { return area() == other.area(); }
  bool operator!=(const Shape &other) const { return !(*this == other); }
};
int Shape::idCounter = 0;

class Rectangle : public Shape {
protected:
  double width, height;

public:
  Rectangle(double w, double h) {
    width = w;
    height = h;
  }
  double area() const override { return width * height; }
  void show() const override {
    print << Info << "Rectangle ID: " << getId() << " Area: " << area() << Clr
          << e;
  }
  double perimeter() const { return 2 * (width + height); }
};

class Cuboid : public Rectangle {
private:
  double depth;

public:
  Cuboid(double w, double h, double d) : Rectangle(w, h) { depth = d; }
  double volume() const { return width * height * depth; }
  void show() const override {
    print << Success << "Cuboid ID: " << getId() << " Volume: " << volume()
          << Clr << e;
  }
};

class Circle : public Shape {
protected:
  double radius;

public:
  Circle(double r) : radius(r) {}
  double area() const override { return M_PI * radius * radius; }
  void show() const override {
    print << Info << "Circle ID: " << getId() << " Area: " << area() << Clr
          << e;
  }
  double circumference() const { return 2 * M_PI * radius; }
};

class Sphere : public Circle {
public:
  Sphere(double r) : Circle(r) {}
  double volume() const {
    return (4.0 / 3.0) * M_PI * radius * radius * radius;
  }
  void show() const override {
    print << Success << "Sphere ID: " << getId() << " Volume: " << volume()
          << Clr << e;
  }
};

int main() {
  vector<unique_ptr<Shape>> shapes;
  shapes.push_back(make_unique<Rectangle>(5, 10));
  shapes.push_back(make_unique<Cuboid>(5, 10, 15));
  shapes.push_back(make_unique<Circle>(7));
  shapes.push_back(make_unique<Sphere>(7));

  for (const auto &shape : shapes) {
    shape->show();
  }
  return 0;
}
