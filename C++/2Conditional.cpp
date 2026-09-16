//////////////////////////////////////////////////////////////////////////////////////////

// #include <iostream>
// int main() {
//     int battery_level = 15;
//     if (battery_level < 20) {
//         std::cout << "Low battery, return to charge" << std::endl;
//     } else {
//         std::cout << "Battery OK" << std::endl;
//     }
//     return 0;
// }

//////////////////////////////////////////////////////////////////////////////////////////

// Declares an int distance_to_wall set to 5 (imagine this is from a robot's ultrasonic sensor, in cm)
// If distance_to_wall is less than 10, print "Obstacle detected! Stop."
// Otherwise, print "Path is clear."

#include <iostream>
int main() {
    int distance_to_wall = 5;
    if (distance_to_wall < 10) {
        std::cout << " Obstacle detected ! Stop. " << std::endl;
    } else {
        std::cout << "Path is clear " << std::endl;
    }
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////

/* 

#include <iostream>  // Imports tools needed to print text on the screen.
int main() {         // Starts the main container where the program begins running.
    int distance_to_wall = 5;  // Creates a variable storing the distance to the obstacle.
    if (distance_to_wall < 10) {  // Checks if the distance is less than ten.
        std::cout << " Obstacle detected ! Stop. " << std::endl;  // Prints a warning message on the screen.
    } else {  // Sets up the alternative plan if the check fails.
        std::cout << "Path is clear " << std::endl;  // Prints a safe status message on the screen.
    }  // Closes the decision-making conditional block.
    return 0;  // Signals to the operating system that the program ran successfully.
}  // Marks the official end of the entire C++ program.

*/

//////////////////////////////////////////////////////////////////////////////////////////

// To execute // g++ 2Conditional.cpp -o 2Conditional.exe; .\2Conditional.exe