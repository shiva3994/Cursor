// Project 1: Obstacle-Avoidance Simulator

// What it does: simulates a robot checking 5 sensors, printing each reading's status,
// then giving one final decision.

// Part A — set up the array (you know this):

#include <iostream> 
int main() {
    int sensor_readings[5] = {12, 8, 15, 3, 20};
    retutn 0;
}

// Part B — add a loop that checks each sensor and prints its status 
// (combines things you already know: loops + if/else + arrays):

for (int i = 0; i < 5; i++) {
    if (sensor_readings[i] < 10) {
        std::cout << "Sensor" << i << ": Danger - Obstacle at " << sensor_readings[i] << "cm" << std::endl;
    } else {
        std::cout << "Sensor" << i << ": Clear - No Obstacle" << sensor_readings[i] << "cm" << std::endl;
    }
}

// Part C — the new bit: track if any sensor found danger, using a bool:

bool obstacle_found = false;

// inside the if(danger) block, add:
obstacle_found = true;