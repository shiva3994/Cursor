// int age = 25;          // whole numbers
// double price = 9.99;   // decimals
// char grade = 'A';      // single character
// bool isReady = true;   // true/false
// string name = "Shiva"; // text (needs #include <string>) 

//TESK 1
//Declare an int variable called battery_level and set it to 85
//Print "Battery level: 85%" using std::cout

#include <iostream>

int main() {
    int battery_level = 85;
    std::cout << "Battery level: " << battery_level << "%" << std::endl;
    return 0;
}