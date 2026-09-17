#include <iostream>                          // for std::cout

void chargeRobot(int &battery) {              // the & means "reference" — this connects directly to the ORIGINAL variable, not a copy
    battery = battery + 20;                   // changes made here actually change the original variable outside the function
}

int main() {                                  // program starts here
    int rover_battery = 10;                   // starting battery level

    std::cout << "Before: " << rover_battery << "%" << std::endl;  // print before charging

    chargeRobot(rover_battery);               // call function, passing rover_battery BY REFERENCE

    std::cout << "After: " << rover_battery << "%" << std::endl;   // print after — it actually changed!

    return 0;                                 // program finished successfully
}

// g++ 11References.cpp -o 11References.exe; .\11References.exe