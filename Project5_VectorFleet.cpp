#include <iostream>                          // for std::cout
#include <string>                             // for std::string
#include <vector>                             // for std::vector

struct Robot {                                // same Robot blueprint as before
    std::string name;
    int battery_level;
    int position;
};

void reportStatus(Robot r) {                  // same function as before
    std::cout << "Robot: " << r.name << std::endl;
    std::cout << "Battery: " << r.battery_level << "%" << std::endl;
    std::cout << "Position: " << r.position << std::endl;
}

int main() {
    std::vector<Robot> fleet;                 // empty, resizable list of Robots (instead of Robot fleet[3])
    
    // TODO: create 3 separate Robot variables (like Robot r1; r1.name = "..."; etc.)
    //       then use fleet.push_back(r1); to add each one to the vector

    r0.name = "Rover 0";
    fleet.push_back(r0);

    r1.name = "Rover 1"; 
    fleet.push_back(r1);
    
    r2.name = "Rover 2"; 
    fleet.push_back(r2);
    
    // TODO: loop through the fleet using fleet.size() instead of a fixed number like 3,
    //       call reportStatus() on each, and warn if battery_level < 30

    for (int i = 0; i < 3; i++) {                       // loop through all 3 robots (index 0 to 2)
        reportStatus(fleet[i]);                         // print this robot's full status using the function
        if (fleet[i].battery_level < 30) {              // check if this robot's battery is low
            std::cout << "WARNING: " << fleet[i].name << " needs charging!" << std::endl;  // print warning
        }
    }   
    
    return 0;
}

// g++ Project5_VectorFleet.cpp -o Project5_VectorFleet.exe; .\Project5_VectorFleet.exe