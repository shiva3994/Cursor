#include <iostream>                          // for std::cout
#include <string>                             // for std::string
#include <vector>                             // for std::vector

struct Robot {                                // blueprint for a Robot
    std::string name;                         // field: robot's name
    int battery_level;                        // field: battery percentage
    int position;                             // field: robot's position
};                                             // end of struct definition

void reportStatus(Robot r) {                  // function takes a whole Robot as parameter
    std::cout << "Robot: " << r.name << std::endl;                     // print name
    std::cout << "Battery: " << r.battery_level << "%" << std::endl;   // print battery
    std::cout << "Position: " << r.position << std::endl;              // print position
}                                              // end of reportStatus function

int main() {                                  // program starts here
    std::vector<Robot> fleet;                 // empty, resizable list of Robots

    Robot r0;                                 // declare r0
    r0.name = "Rover 0";                      // set r0's name
    r0.battery_level = 10;                    // set r0's battery (low, to test warning)
    r0.position = 0;                          // set r0's position
    fleet.push_back(r0);                      // add r0 to the end of the fleet vector

    Robot r1;                                 // declare r1
    r1.name = "Rover 1";                      // set r1's name
    r1.battery_level = 90;                    // set r1's battery
    r1.position = 0;                          // set r1's position
    fleet.push_back(r1);                      // add r1 to the fleet vector

    Robot r2;                                 // declare r2
    r2.name = "Rover 2";                      // set r2's name
    r2.battery_level = 88;                    // set r2's battery
    r2.position = 0;                          // set r2's position
    fleet.push_back(r2);                      // add r2 to the fleet vector

    for (int i = 0; i < fleet.size(); i++) {  // loop through the fleet; size() adapts automatically
        reportStatus(fleet[i]);               // print this robot's full status
        if (fleet[i].battery_level < 30) {    // check if this robot's battery is low
            std::cout << "WARNING: " << fleet[i].name << " needs charging!" << std::endl;  // print warning
        }
    }                                          // loop ends after checking every robot

    return 0;                                 // program finished successfully
}

// g++ Project5_VectorFleet.cpp -o Project5_VectorFleet.exe; .\Project5_VectorFleet.exe