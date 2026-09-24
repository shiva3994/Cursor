#include <iostream>                           // for std::cout
#include <string>                             // for std::string

class Robot {                                 // blueprint: data + functions together
private:                                      // hidden: main() cannot touch these directly
    std::string name;                         // field: robot's name (private)
    int battery_level;                        // field: battery % (private)

public:                                       // buttons main() IS allowed to press
    Robot(std::string n, int b) {             // constructor: runs when you create a Robot
        name = n;                             // store the name inside this robot
        battery_level = b;                    // store the battery inside this robot
    }

    int getBattery() {                        // getter: let outside code READ battery only
        return battery_level;                 // hand back a copy of the number
    }

    void charge() {                           // method: the safe way to raise battery
        battery_level = battery_level + 20;   // add 20%
        if (battery_level > 100) {            // do not go over 100
            battery_level = 100;
        }
    }

    void report() {                           // method: print this robot's status
        std::cout << name << ": " << battery_level << "%" << std::endl;
    }
};                                            // semicolon required after the class

int main() {                                  // program starts here
    Robot r1("Rover1", 10);                   // constructor sets private fields in one line

    r1.report();                              // OK: report() is public
    // r1.battery_level = 999;                // ERROR if uncommented — battery is private
    std::cout << "Read battery: " << r1.getBattery() << "%\n";  // OK: use getter

    r1.charge();                              // OK: charge() is allowed to change private data
    r1.report();                              // should now show 30%

    return 0;                                 // success
}

// g++ 15Private.cpp -o 15Private.exe; .\15Private.exe