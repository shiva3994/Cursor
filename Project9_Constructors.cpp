// Project 9: Fleet with Constructors
// Task: constructor sets name, battery_level, position in one line.
// Create robots like: Robot r0("Rover 0", 10, 0);

#include <iostream>                           // for std::cout
#include <string>                             // for std::string
#include <vector>                             // for std::vector (resizable list)

class Robot {                                 // blueprint: data + functions together
public:                                       // usable from main()
    std::string name;                         // field: robot's name
    int battery_level;                        // field: battery percentage
    int position;                             // field: robot's position

    Robot(std::string n, int b, int p) {      // CONSTRUCTOR: same name as class, no return type
        name = n;                             // n → this robot's name
        battery_level = b;                    // b → this robot's battery
        position = p;                         // p → this robot's position
    }                                         // runs automatically when you write Robot r0(...)

    void charge() {                           // method: uses THIS robot's battery
        battery_level = battery_level + 20;   // add 20%
        if (battery_level > 100) {            // cap at full
            battery_level = 100;
        }
    }

    void report() {                           // method: print THIS robot
        std::cout << "Robot: " << name << std::endl;
        std::cout << "Battery: " << battery_level << "%" << std::endl;
        std::cout << "Position: " << position << std::endl;
    }
};                                            // semicolon required after the class

int main() {
    std::vector<Robot> fleet;                 // empty list of Robot objects

    Robot r0("Rover 0", 10, 0);               // constructor: name, battery, position in ONE line
    fleet.push_back(r0);                      // add r0 to the fleet (low battery on purpose)

    Robot r1("Rover 1", 90, 0);               // same shorter style as lesson 14
    fleet.push_back(r1);

    Robot r2("Rover 2", 88, 0);
    fleet.push_back(r2);

    for (int i = 0; i < fleet.size(); i++) {  // visit every robot
        fleet[i].report();                    // print this robot

        if (fleet[i].battery_level < 30) {    // same low-battery rule as Project 8
            std::cout << "WARNING: " << fleet[i].name << " needs charging!" << std::endl;
            fleet[i].charge();                // charge THIS robot
            std::cout << "After charge: ";
            fleet[i].report();                // show 10% → 30%
        }
    }

    return 0;                                 // success
}

// g++ Project9_Constructors.cpp -o Project9_Constructors.exe; .\Project9_Constructors.exe