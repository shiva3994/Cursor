#include <iostream>              // for std::cout
#include <vector>                // needed to use std::vector

int main() {                     // program starts here
    std::vector<int> readings;   // creates an EMPTY, resizable list of ints (unlike arrays, no fixed size needed)

    readings.push_back(22);      // adds 22 to the end of the list
    readings.push_back(8);       // adds 8 to the end
    readings.push_back(15);      // adds 15 to the end

    std::cout << "Very First reading: " << readings[0] << std::endl;   // access like an array, with [ ]
    std::cout << "Total number readings: " << readings.size() << std::endl;  // .size() tells you how many items are in it

    return 0;                    // program finished successfully
}

//  g++ 10Vectors.cpp -o 10Vectors.exe; .\10Vectors.exe