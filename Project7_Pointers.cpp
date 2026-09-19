#include <iostream>                                    // for std::cout

int* findClosest(int arr[], int size) {                // function returns a POINTER to an int
    int smallestIndex = 0;                              // assume the first element is smallest, to start

    for (int i = 1; i < size; i++) {                    // loop through the rest of the array (index 1 onward)
        if (arr[i] < arr[smallestIndex]) {              // is this element smaller than our current smallest?
            smallestIndex = i;                          // if yes, remember this new index instead
        }
    }                                                    // loop ends after checking all elements

    return &arr[smallestIndex];                         // return the ADDRESS of the smallest element (a pointer)
}                                                        // end of findClosest function

int main() {                                            // program starts here
    int sensor_readings[5] = {12, 8, 15, 3, 20};        // 5 fake sensor distances (cm)

    int* closest = findClosest(sensor_readings, 5);     // call the function, store the returned pointer

    std::cout << "Closest obstacle: " << *closest << "cm" << std::endl;  // dereference (*) to get the actual value

    return 0;                                           // program finished successfully
}