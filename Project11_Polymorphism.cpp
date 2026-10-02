// Project 11: Polymorphic Sensor Array
// Create a base Sensor class (type, is_active, read() virtual method).
// Create three subclasses: DistanceSensor, TemperatureSensor, and
// BatterySensor, each overriding read() to output their specific data. In
// main(), create one of each, store their addresses in an array of Sensor*
// pointers, and loop through the array calling read() on each sensor.

#include <iostream>
#include <string>

class Sensor {
public:
  std::string type;
  bool is_active;

  Sensor(std::string t, bool active = true) {
    type = t;
    is_active = active;
  }

  // 'virtual' ensures dynamic dispatch at runtime
  virtual void read() {
    if (!is_active) {
      std::cout << "[" << type << "] Sensor is offline." << std::endl;
      return;
    }
    std::cout << "[" << type << "] Generic sensor reading." << std::endl;
  }

  // Virtual destructor
  virtual ~Sensor() {}
};

class DistanceSensor : public Sensor {
public:
  double distance_cm;

  DistanceSensor(std::string t, double dist) : Sensor(t) { distance_cm = dist; }

  void read() override {
    std::cout << "[" << type << "] Obstacle distance: " << distance_cm << " cm"
              << std::endl;
  }
};

class TemperatureSensor : public Sensor {
public:
  double temp_celsius;

  TemperatureSensor(std::string t, double temp) : Sensor(t) {
    temp_celsius = temp;
  }

  void read() override {
    std::cout << "[" << type << "] Motor temperature: " << temp_celsius << " C"
              << std::endl;
  }
};

class BatterySensor : public Sensor {
public:
  int percentage;

  BatterySensor(std::string t, int pct) : Sensor(t) { percentage = pct; }

  void read() override {
    std::cout << "[" << type << "] Battery remaining: " << percentage << "%"
              << std::endl;
  }
};

int main() {
  DistanceSensor s1("UltrasonicFront", 24.5);
  TemperatureSensor s2("CoreThermometer", 41.2);
  BatterySensor s3("MainPack", 88);

  // Array of base class pointers pointing to different derived sensors
  Sensor *sensors[3] = {&s1, &s2, &s3};

  std::cout << "--- Sensor Diagnostic Scan ---" << std::endl;

  // Single loop calling read() on each — polymorphism dynamically triggers
  // each sensor's specific override!
  for (int i = 0; i < 3; i++) {
    sensors[i]->read();
  }

  return 0;
}

// g++ Project11_Polymorphism.cpp -o Project11_Polymorphism.exe;
// .\Project11_Polymorphism.exe
