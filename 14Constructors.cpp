#include <iostream>              // for std::cout
#include <string>                // for std::string

class Robot {                    // class definition
public:
    std::string name;
    int battery_level;

    Robot(std::string n, int b) {          // CONSTRUCTOR: same name as the class, runs automatically when created
        name = n;                          // sets the fields using the values passed in
        battery_level = b;
    }

    void report() {
        std::cout << name << ": " << battery_level << "%" << std::endl;
    }
};

int main() {
    Robot r1("Rover1", 85);       // one line instead of three! the constructor runs automatically
    r1.report();

    return 0;
}

// g++ 14Constructors.cpp -o 14Constructors.exe; .\14Constructors.exe