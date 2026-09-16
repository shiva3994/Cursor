#include <iostream>                          // for std::cout
#include <string>                             // for std::string

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

int main() {                                            // program starts here
    Robot fleet[3];                                     // array holding 3 Robots

    fleet[0].name = "Rover 0";                           // set 1st robot's name
    fleet[0].battery_level = 10;                        // set 1st robot's battery (low, for testing warning)
    fleet[0].position = 0;                              // set 1st robot's position

    fleet[1].name = "Rover 1";                           // set 2nd robot's name
    fleet[1].battery_level = 90;                        // set 2nd robot's battery
    fleet[1].position = 0;                              // set 2nd robot's position

    fleet[2].name = "Rover 2";                           // set 3rd robot's name
    fleet[2].battery_level = 88;                        // set 3rd robot's battery
    fleet[2].position = 0;                              // set 3rd robot's position

    for (int i = 0; i < 3; i++) {                       // loop through all 3 robots (index 0 to 2)
        reportStatus(fleet[i]);                         // print this robot's full status using the function
        if (fleet[i].battery_level < 30) {              // check if this robot's battery is low
            std::cout << "WARNING: " << fleet[i].name << " needs charging!" << std::endl;  // print warning
        }
    }                                                    // loop ends after checking all 3 robots

    return 0;                                           // program finished successfully
}

//  g++ Project4_Fleet.cpp -o Project4_Fleet.exe; .\Project4_Fleet.exe