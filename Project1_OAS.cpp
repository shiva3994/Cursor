// Project 1: Obstacle-Avoidance Simulator

// What it does: simulates a robot checking 5 sensors, printing each reading's status,
// then giving one final decision.
#include <iostream>                              // needed for std::cout

int main() {                                     // program starts here
    int sensor_readings[5] = {12, 8, 15, 3, 20};  // 5 fake sensor distances (cm)

    bool obstacle_found = false;                  // tracks if ANY sensor saw danger; starts false

    for (int i = 0; i < 5; i++) {                 // check each of the 5 sensors, one by one
        if (sensor_readings[i] < 10) {            // is this sensor too close? (danger zone)
            std::cout << "Sensor " << i << ": DANGER - obstacle at " << sensor_readings[i] << "cm" << std::endl;  // report danger
            obstacle_found = true;                // remember that at least one sensor found danger
        } else {                                  // otherwise, this sensor is fine
            std::cout << "Sensor " << i << ": clear - " << sensor_readings[i] << "cm" << std::endl;  // report clear
        }
    }                                              // loop ends after checking all 5 sensors

    if (obstacle_found) {                         // check what we remembered across the whole loop
        std::cout << "ACTION: STOP" << std::endl; // if ANY sensor found danger, stop the robot
    } else {
        std::cout << "ACTION: PROCEED" << std::endl;  // only reached if ALL sensors were clear
    }

    return 0;                                     // program finished successfully
}

// g++ Project1_OAS.cpp -o Project1_OAS.exe; .\Project1_OAS.exe