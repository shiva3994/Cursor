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

int main() {                                  // program starts here
    Robot fleet[3];                           // array holding 3 Robots

    // TODO: set fleet[0].name, fleet[0].battery_level, fleet[0].position (and same for [1], [2])

    // TODO: use a for loop (i = 0 to 2) to call reportStatus(fleet[i])
    //       and print a warning if fleet[i].battery_level < 30

    return 0;                                 // program finished successfully
}