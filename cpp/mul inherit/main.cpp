#include "../../../../.mylibs/lifeEasier.hpp"

class ElectricVehicle {
protected:
  int batteryLevel;

public:
  ElectricVehicle() : batteryLevel(100) {}
  void charge(int amount) {
    batteryLevel = std::min(100, batteryLevel + amount);
    print << Success << "Battery charged. Level: " << batteryLevel << "%" << Clr
          << e;
  }
  void showBattery() const {
    print << Info << "Battery Level: " << batteryLevel << "%" << Clr << e;
  }
};

class LandTransport {
protected:
  int speed;

public:
  LandTransport() : speed(0) {}
  virtual void accelerate(int value) {
    speed += value;
    print << Success << "Speed increased to " << speed << " km/h" << Clr << e;
  }
  virtual void brake(int value) {
    speed = std::max(0, speed - value);
    print << Crit << "Speed reduced to " << speed << " km/h" << Clr << e;
  }
};

class WaterTransport {
protected:
  int depth;

public:
  WaterTransport() : depth(0) {}
  virtual void dive(int value) {
    depth += value;
    print << Success << "Dived to depth " << depth << " meters" << Clr << e;
  }
  virtual void surface(int value) {
    depth = std::max(0, depth - value);
    print << Crit << "Surfaced to depth " << depth << " meters" << Clr << e;
  }
};

class ElectricCar : public virtual ElectricVehicle, public LandTransport {
public:
  void accelerate(int value) override {
    speed += value;
    print << Success << "Electric car speed increased to " << speed << " km/h"
          << Clr << e;
  }
  void brake(int value) override {
    speed = std::max(0, speed - value);
    print << Crit << "Electric car speed reduced to " << speed << " km/h" << Clr
          << e;
  }
  void driveMode() {
    print << Info << "Electric car is driving at " << speed << " km/h" << Clr
          << e;
  }
};

class ElectricBoat : public virtual ElectricVehicle, public WaterTransport {
public:
  void dive(int value) override {
    depth += value;
    print << Success << "Electric boat dived to " << depth << " meters" << Clr
          << e;
  }
  void surface(int value) override {
    depth = std::max(0, depth - value);
    print << Crit << "Electric boat surfaced to " << depth << " meters" << Clr
          << e;
  }
  void sailMode() {
    print << Info << "Electric boat is sailing at depth " << depth << " meters"
          << Clr << e;
  }
};

class AmphibiousVehicle : public ElectricCar, public ElectricBoat {
private:
  bool landMode;

public:
  AmphibiousVehicle() : landMode(true) {}
  void switchToLandMode() {
    landMode = true;
    print << Success << "Switched to Land Mode" << Clr << e;
  }
  void switchToWaterMode() {
    landMode = false;
    print << Success << "Switched to Water Mode" << Clr << e;
  }
  void move() {
    if (landMode) {
      driveMode();
    } else {
      sailMode();
    }
  }
};

int main() {
  AmphibiousVehicle av;
  av.showBattery();
  av.accelerate(30);
  av.move();
  av.switchToWaterMode();
  av.dive(10);
  av.move();
  av.charge(20);
  av.showBattery();
  return 0;
}