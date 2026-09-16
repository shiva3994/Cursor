//////////////////////////////////////////////////////////////////////////////////////////

// Counting down a robot's remaining battery checks:

// #include <iostream>
// int main() {
//     for (int i = 1; i <= 3; i++) {
//         std::cout << "Battery check " << i << ": level OK" << std::endl;
//     }
//     return 0;

//////////////////////////////////////////////////////////////////////////////////////////

// Use a for loop to count from 1 to 5 (scan number)
// Each time through, print something like "Scan 1: distance = 5cm", "Scan 2: distance = 5cm", etc.

#include <iostream>
int main() {
    for (int i = 1; i <= 5; i++) {
        std::cout << " Scan " << i << ": distance = 5cm " << std::endl;
    }
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////

/* 

#include <iostream>  // Imports tools needed to print text on the screen.
int main() {         // Starts the main container where the program begins running.
    for (            // Sets up a loop to repeat a task multiple times.
        int i = 1;   // Creates a loop counter variable starting at number one.
        i <= 5;      // Sets the rule to stop the loop after five rounds.
        i++          // Adds one to the counter after every single turn.
    ) {              // Opens the block of code that will be repeated.
        std::cout << " Scan " << i << ": distance = 5cm " << std::endl;  // Prints the text, counter, and a new line.
    }                // Closes the loop block so it can restart or exit.
    return 0;        // Signals to the operating system that the program ran successfully.
}                    // Marks the official end of the entire C++ program.

*/

//////////////////////////////////////////////////////////////////////////////////////////

// g++ 3Loops.cpp -o 3Loops.exe; .\3Loops.exe