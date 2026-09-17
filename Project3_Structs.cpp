#include <iostream>              // for std::cout
#include <string>                // needed to use std::string

struct Robot {                   // defines a new "blueprint" type called Robot
    std::string name;            // field: robot's name (text)
    int battery_level;           // field: battery percentage (whole number)
    int position;                // field: robot's position (whole number)
};                                // semicolon required at the end of a struct definition

void reportStatus(Robot r) {                          // function takes a whole Robot as its parameter
    std::cout << "Robot: " << r.name << std::endl;    // print the robot's name
    std::cout << "Battery: " << r.battery_level << "%" << std::endl;  // print battery
    std::cout << "Position: " << r.position << std::endl;             // print position
}                                                       // end of reportStatus function

int main() {                     // program starts here
    Robot r1;                    // create an actual Robot using the blueprint, called r1
    r1.name = "Rover1";          // set r1's name field
    r1.battery_level = 85;       // set r1's battery_level field
    r1.position = 0;             // set r1's position field

    reportStatus(r1);            // call the function, passing in r1

    return 0;                    // program finished successfully
}

// g++ Project3_Structs.cpp -o Project3_Structs.exe; .\Project3_Structs.exe