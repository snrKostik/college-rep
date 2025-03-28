#include "../../../../.mylibs/lifeEasier.hpp"

class Vehicle {
public:
    virtual void showType() const = 0;
    virtual ~Vehicle() {
        print << Log << "Vehicle destroyed" << Clr << e;
    }
};

class Car : public Vehicle {
public:
    Car() {
        print << Success << "Car created" << Clr << e;
    }
    void showType() const override {
        print << Info << "This is a Car" << Clr << e;
    }
    ~Car() {
        print << Crit << "Car destroyed" << Clr << e;
    }
};

class Bike : public Vehicle {
public:
    Bike() {
        print << Success << "Bike created" << Clr << e;
    }
    void showType() const override {
        print << Info << "This is a Bike" << Clr << e;
    }
    ~Bike() {
        print << Crit << "Bike destroyed" << Clr << e;
    }
};

int main() {
    const int size = 2;
    unique_ptr<Vehicle> vehicles[size] = { make_unique<Car>(), make_unique<Bike>() };
    
    for (const auto &vehicle : vehicles) {
        vehicle->showType();
    }
}
