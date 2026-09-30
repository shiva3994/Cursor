#include <iostream>              // for std::cout
#include <string>                // for std::string

class Robot {                    // the "base" class — general robot
public:
    std::string name;
    int battery_level;

    Robot(std::string n, int b) {
        name = n;
        battery_level = b;
    }

    void report() {
        std::cout << name << ": " << battery_level << "%" << std::endl;
    }
};

class ScoutRobot : public Robot {          // ScoutRobot INHERITS everything from Robot
public:
    int speed;                             // plus its own extra field

    ScoutRobot(std::string n, int b, int s) : Robot(n, b) {   // calls Robot's constructor first, then sets speed
        speed = s;
    }

    void sprint() {                        // a method only ScoutRobots have
        std::cout << name << " sprints at speed " << speed << std::endl;
    }
};

int main() {
    ScoutRobot s1("Scout1", 70, 15);       // creates a ScoutRobot

    s1.report();                           // uses the INHERITED method from Robot
    s1.sprint();                           // uses ScoutRobot's own new method

    return 0;
}

// g++ 16Inheritance.cpp -o 16Inheritance.exe; .\16Inheritance.exe