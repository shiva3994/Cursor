// Task: convert your struct Robot + separate reportStatus()/chargeRobot() functions
// (from Projects 3–6) into a proper class with report() and charge() as methods.
// Then recreate your fleet (vector of Robots) from Project 5, and for any robot under 30% battery,
// call .charge() directly on it instead of passing it to an outside function.

#include <iostream>                           // for std::cout
#include <string>                             // for std::string
#include <vector>                             // for std::vector (resizable list)

class Robot {                                 // blueprint: data + functions together
public:                                       // these members can be used from main()
    std::string name;                         // field: robot's name
    int battery_level;                        // field: battery percentage
    int position;                             // field: robot's position

    void charge() {                           // method: uses THIS robot's battery (no extra argument)
        battery_level = battery_level + 20;   // add 20%
        if (battery_level > 100) {            // do not go over a full battery
            battery_level = 100;
        }
    }

    void report() {                           // method: print THIS robot's status
        std::cout << "Robot: " << name << std::endl;
        std::cout << "Battery: " << battery_level << "%" << std::endl;
        std::cout << "Position: " << position << std::endl;
    }
};                                            // semicolon required after the class

int main() {
    std::vector<Robot> fleet;                 // empty list of Robot objects

    Robot r0;                                 // first rover (low battery on purpose)
    r0.name = "Rover 0";
    r0.battery_level = 10;                    // under 30% — will get .charge()
    r0.position = 0;
    fleet.push_back(r0);                      // add r0 to the fleet

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

    for (int i = 0; i < fleet.size(); i++) {  // visit every robot in the fleet
        fleet[i].report();                    // call report() ON this robot (not reportStatus(r))

        if (fleet[i].battery_level < 30) {    // same low-battery check as Project 5
            std::cout << "WARNING: " << fleet[i].name << " needs charging!" << std::endl;
            fleet[i].charge();                // charge THIS robot; no outside chargeRobot()
            std::cout << "After charge: ";
            fleet[i].report();                // print again so you see 10% → 30%
        }
    }

    return 0;
}

// g++ Project8_Classes.cpp -o Project8_Classes.exe; .\Project8_Classes.exe