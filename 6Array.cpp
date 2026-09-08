// Declare the same array: int sensor_readings[5] = {12, 8, 15, 3, 20};
// Use a for loop to calculate the total sum of all values
// Calculate the average (sum divided by 5) — use a double for this, since averages often aren't whole numbers

#include <iostream>              // needed for std::cout

int main() {                     // program entry point
    int sensor_readings[5] = {12, 8, 15, 3, 20};  // our 5 fake sensor values

    int sum = 0;                 // start a running total at zero
    for (int i = 0; i < 5; i++) {           // loop through all 5 elements (index 0 to 4)
        sum = sum + sensor_readings[i];     // add each value to the running total
    }

    std::cout << "Total: " << sum << std::endl;  // print the final sum
    return 0;                    // program finished successfully
}


// Each time through the loop:
// i increases by 1 (that's the i++ part)
// The loop checks i < 5 — as soon as i becomes 5, the condition is false, and the loop stops 
// (so it never tries sensor_readings[5], which doesn't exist)
// sum = sum + sensor_readings[i] grabs whatever value is currently in sum, 
// adds the current array element to it, and stores the result back into sum


// g++ 6Array.cpp -o 6Array.exe; .\6Array.exe