// Declare an array of 5 ints called sensor_readings with values {12, 8, 15, 3, 20}
// Use a for loop (like you just learned!) to print each value, one per line.

#include <iostream>              // gives us access to std::cout for printing

int main() {                     // program starts here
    int sensor_readings[5] = {12, 8, 15, 3, 20};  // array of 5 fake sensor distances

    int smallest = sensor_readings[0];  // assume the first value is smallest, for now

    for (int i = 1; i < 5; i++) {       // loop through remaining elements (index 1 to 4)
        if (sensor_readings[i] < smallest) {  // is this one smaller than what we've found so far?
            smallest = sensor_readings[i];    // if yes, update "smallest"
        }
    }

    std::cout << "Closest obstacle: " << smallest << "cm" << std::endl;  // print final answer

    return 0;                    // tells the OS the program finished successfully
}

// g++ 5ArrayMin.cpp -o 5ArrayMin.exe; .\5ArrayMin.exe
