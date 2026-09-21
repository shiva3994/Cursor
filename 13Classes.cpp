#include <iostream>              // for std::cout
#include <string>                // for std::string

class Robot {                    // classes are like structs, but can also hold FUNCTIONS
public:                          // "public" means these are accessible from outside the class
    std::string name;            // field: robot's name
    int battery_level;           // field: battery percentage

    void charge() {              // a FUNCTION that lives inside the class — called a "method"
        battery_level = battery_level + 20;   // uses the class's own data directly, no parameter needed
        if (battery_level > 100) {
            battery_level = 100;
        }
    }

    void report() {              // another method — prints this robot's own status
        std::cout << name << ": " << battery_level << "%" << std::endl;
    }
};                                // end of class definition

int main() {                     // program starts here
    Robot r1;                    // create a Robot (same as struct)
    r1.name = "Rover1";
    r1.battery_level = 10;

    r1.report();                 // call the method using dot notation, just like a field
    r1.charge();                 // charge it — no need to pass battery_level in, the method knows its own data
    r1.report();                 // print again to see the change

    return 0;                    // program finished successfully
}