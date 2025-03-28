#include "../../../../.mylibs/lifeEasier.hpp"

// #include <memory>

void convertTemperature(double tempCelsius) {
  double tempFahrenheit = (tempCelsius * 9.0 / 5.0) + 32.0;
  print << "Цельсий: " << tempCelsius << " -> Фаренгейт: " << tempFahrenheit
        << e;
  print << "Цельсий (int): " << static_cast<int>(tempCelsius)
        << " -> Фаренгейт (int): " << static_cast<int>(tempFahrenheit) << e;
}

//----------

class Vehicle {
public:
  virtual void showType() const = 0;
  virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
  void showType() const override { print << "Это легковой автомобиль." << e; }
};

class Truck : public Vehicle {
public:
  void showType() const override { print << "Это грузовой автомобиль." << e; }
};

int main() {
  double tempCelsius = 36.6;
  convertTemperature(tempCelsius);

  //----------

  vector<std::unique_ptr<Vehicle>> vehicles;
  vehicles.push_back(std::make_unique<Car>());
  vehicles.push_back(std::make_unique<Truck>());
  vehicles.push_back(std::make_unique<Car>());

  for (const auto &vehicle : vehicles) {
    vehicle->showType();
  }
}
