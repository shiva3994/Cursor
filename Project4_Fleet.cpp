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

    fleet[0].name = 'Rover0';
    fleet[0].battery_level = 10;
    fleet[0].position = 0;

    fleet[1].name = 'Rover1';
    fleet[1].battery_level = 90;
    fleet[1].position = 0;

    fleet[2].name = 'Rover2';
    fleet[2].battery_level = 88;
    fleet[2].position = 0;

    std::cout << fleet[0].name << ": " << fleet[0].battery_level << "%" << std::endl;  // print 1st robot
    std::cout << fleet[1].name << ": " << fleet[1].battery_level << "%" << std::endl;  // print 2nd robot
    std::cout << fleet[2].name << ": " << fleet[2].battery_level << "%" << std::endl;  // print 3rd robot

    // TODO: use a for loop (i = 0 to 2) to call reportStatus(fleet[i])
    //       and print a warning if fleet[i].battery_level < 30

    return 0;                                 // program finished successfully
}


//  g++ Project4_Fleet.cpp -o Project4_Fleet.exe; .\Project4_Fleet.exe