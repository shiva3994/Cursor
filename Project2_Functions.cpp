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