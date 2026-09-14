// it's just meant to hold the standalone concept, not a runnable program

#include <iostream>              // for std::cout
#include <string>                // needed to use std::string

struct Robot {                   // defines a new "blueprint" type called Robot
    std::string name;            // field: robot's name (text)
    int battery_level;           // field: battery percentage (whole number)
    int position;                // field: robot's position (whole number)
};                                // semicolon required at the end of a struct definition

// g++ 8Structs.cpp -o 8Structs.exe; .\8Structs.exe