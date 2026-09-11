#include <iostream>                          // gives access to std::cout for printing

void check_sensor(int distance) {            // defines a function named check_sensor, takes one int parameter, returns nothing (void)
    if (distance < 10) {                     // check if the distance is under 10cm
        std::cout << "DANGER" << std::endl;  // print DANGER if too close
    } else {                                 // otherwise (10 or more)
        std::cout << "clear" << std::endl;   // print clear
    }
}                                             // end of check_sensor function

int main() {                                 // program starts here
    check_sensor(5);                         // call the function, passing in 5 → will print DANGER
    check_sensor(20);                        // call the function again, passing in 20 → will print clear
    return 0;                                // program finished successfully
}

// g++ 7Functions.cpp -o 7Functions.exe; .\7Functions.exe