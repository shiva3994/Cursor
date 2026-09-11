#include <iostream>                                    // for std::cout

bool checkSensor(int distance, int sensorNumber) {      // function that checks ONE sensor, returns true/false
    if (distance < 10) {                                // is this reading in the danger zone?
        std::cout << "Sensor " << sensorNumber << ": DANGER - obstacle at " << distance << "cm" << std::endl;  // report danger
        return true;                                    // send back "true" to whoever called this function
    } else {                                            // otherwise, reading is safe
        std::cout << "Sensor " << sensorNumber << ": clear - " << distance << "cm" << std::endl;  // report clear
        return false;                                   // send back "false"
    }
}   

int main() {                                            // program starts here
    int sensor_readings[5] = {12, 8, 15, 3, 20};        // 5 fake sensor distances (cm)
    bool obstacle_found = false;                        // tracks if ANY sensor found danger; starts false

    for (int i = 0; i < 5; i++) {                       // loop through all 5 sensors
        bool danger = checkSensor(sensor_readings[i], i);  // call the function, store what it returns
        if (danger) {                                   // if THIS sensor returned true (danger)...
            obstacle_found = true;                      // ...remember that overall danger was found
        }