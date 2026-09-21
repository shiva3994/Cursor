// Task: convert your struct Robot + separate reportStatus()/chargeRobot() functions 
// (from Projects 3–6) into a proper class with report() and charge() as methods. 
// Then recreate your fleet (vector of Robots) from Project 5, and for any robot under 30% battery, 
// call .charge() directly on it instead of passing it to an outside function.

#include <iostream>
#include <string>
#include <vector>

class Robot {
public:
    std::string name;
    int battery_level;
    int position;

    void charge() {
        battery_level = battery_level + 20;
        if (battery_level > 100) {
            battery_level = 100;
        }
    }

    void report() {
        std::cout << "Robot: " << name << std::endl;
        std::cout << "Battery: " << battery_level << "%" << std::endl;
        std::cout << "Position: " << position << std::endl;
    }
};

int main() {
    std::vector<Robot> fleet;

    Robot r0;
    r0.name = "Rover 0";
    r0.battery_level = 10;   // under 30% — should charge
    r0.position = 0;
    fleet.push_back(r0);

    Robot r1;
    r1.name = "Rover 1";
    r1.battery_level = 90;
    r1.position = 0;
    fleet.push_back(r1);

    Robot r2;
    r2.name = "Rover 2";
    r2.battery_level = 88;
    r2.position = 0;
    fleet.push_back(r2);

    for (int i = 0; i < fleet.size(); i++) {
        fleet[i].report();

        if (fleet[i].battery_level < 30) {
            std::cout << "WARNING: " << fleet[i].name << " needs charging!" << std::endl;
            fleet[i].charge();           // method on this robot, not an outside function
            std::cout << "After charge: ";
            fleet[i].report();
        }
    }

    return 0;
}

// g++ Project8_Classes.cpp -o Project8_Classes.exe; .\Project8_Classes.exe