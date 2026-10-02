// create a base Robot class (name, battery_level, charge(), report() — reuse from Project 9),
// then two subclasses: ScoutRobot (adds speed, a sprint() method) and HeavyRobot (adds cargo_capacity, a loadCargo()
// method). Create one of each in main(), call their inherited and their own unique methods.

#include <iostream>
#include <string>

class Robot {                              // base class
public:
    std::string name;
    int battery_level;

    Robot(std::string n, int b) {
        name = n;
        battery_level = b;
    }

    void charge() {
        battery_level += 20;
        if (battery_level > 100) battery_level = 100;
    }

    void report() {
        std::cout << name << ": " << battery_level << "%" << std::endl;
    }
};

class ScoutRobot : public Robot {          // inherits Robot
public:
    int speed;

    ScoutRobot(std::string n, int b, int s) : Robot(n, b) {
        speed = s;
    }

    void sprint() {
        std::cout << name << " sprints at speed " << speed << std::endl;
    }
};

class HeavyRobot : public Robot {          // inherits Robot
public:
    int cargo_capacity;

    HeavyRobot(std::string n, int b, int c) : Robot(n, b) {
        cargo_capacity = c;
    }

    void loadCargo() {
        std::cout << name << " loads cargo, capacity " << cargo_capacity << "kg" << std::endl;
    }
};

int main() {
    ScoutRobot s1("Scout1", 70, 15);
    HeavyRobot h1("Hauler1", 50, 200);

    s1.report();       // inherited
    s1.sprint();        // own

    h1.report();        // inherited
    h1.loadCargo();      // own

    return 0;
}

// g++ Project10_Inheritance.cpp -o Project10_Inheritance.exe; .\Project10_Inheritance.exe