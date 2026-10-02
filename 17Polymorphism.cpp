#include <iostream>
#include <string>

class Robot {
public:
  std::string name;

  Robot(std::string n) : name(n) {}

  // 'virtual' tells C++: "If a subclass overrides this method, call their
  // version!"
  virtual void performTask() {
    std::cout << name << " is performing a generic task." << std::endl;
  }

  // Virtual destructor is best practice when using polymorphism
  virtual ~Robot() {}
};

class Drone : public Robot {
public:
  Drone(std::string n) : Robot(n) {}

  // 'override' makes sure we are truly replacing the base class virtual method
  void performTask() override {
    std::cout << name << " is surveying from the air." << std::endl;
  }
};

class Rover : public Robot {
public:
  Rover(std::string n) : Robot(n) {}

  void performTask() override {
    std::cout << name << " is sampling soil on the ground." << std::endl;
  }
};

int main() {
  Drone d1("SkyScout");
  Rover r1("GroundCrawler");

  // Base class pointers pointing to derived objects
  Robot *bot1 = &d1;
  Robot *bot2 = &r1;

  // Both use the same interface, but trigger their specific behaviors!
  bot1->performTask(); // SkyScout is surveying from the air.
  bot2->performTask(); // GroundCrawler is sampling soil on the ground.

  return 0;
}

// g++ 17Polymorphism.cpp -o 17Polymorphism.exe; .\17Polymorphism.exe
