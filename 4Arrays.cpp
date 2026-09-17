//////////////////////////////////////////////////////////////////////////////////
// python Example 

// sensor_readings = [12, 8, 15, 3, 20]
// print(sensor_readings[0]) 

// prints 12

//////////////////////////////////////////////////////////////////////////////////

#include <iostream> 
int main() {
    int sensor_readings[5] = {12, 8, 15, 3, 20};
    std::cout << sensor_readings[0] << std::endl;  
    return 0;
}

// prints 12

// g++ 4Arrays.cpp -o 4Arrays.exe; .\4Arrays.exe