#include <iostream>                                    // for std::cout
#include <string>                                       // for std::string

struct Robot {                                          // same Robot blueprint from Topic 08
    std::string name;                                   // robot's name
    int battery_level;                                  // battery percentage
};

int main() {                                            // program starts here
    Robot fleet[3];                                     // array holding 3 Robots

    fleet[0].name = "Rover1";                           // set name of 1st robot using dot notation + index
    fleet[0].battery_level = 90;                        // set battery of 1st robot

    fleet[1].name = "Rover2";                           // set name of 2nd robot
    fleet[1].battery_level = 60;                        // set battery of 2nd robot

    std::cout << fleet[0].name << ": " << fleet[0].battery_level << "%" << std::endl;  // print 1st robot
    std::cout << fleet[1].name << ": " << fleet[1].battery_level << "%" << std::endl;  // print 2nd robot

    return 0;                                           // program finished successfully
}

// g++ 9ArrayStructs.cpp -o 9ArrayStructs.exe; .\9ArrayStructs.exe