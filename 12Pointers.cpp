#include <iostream>              // for std::cout

int main() {                     // program starts here
    int battery = 85;            // a normal int variable

    int* batteryPtr = &battery;  // a POINTER: stores the memory ADDRESS of battery (the & means "address of")

    std::cout << "Value: " << battery << std::endl;         // prints 85 (the actual value)
    std::cout << "Address: " << batteryPtr << std::endl;    // prints a memory address (some weird-looking number)
    std::cout << "Via pointer: " << *batteryPtr << std::endl;  // the * "dereferences" the pointer — gives back the value it points to (85)

    *batteryPtr = 50;             // changes the ORIGINAL battery variable, through the pointer
    std::cout << "After change: " << battery << std::endl;  // prints 50 — battery itself changed!

    return 0;                     // program finished successfully
}

// g++ 12Pointers.cpp -o 12Pointers.exe; .\12Pointers.exe