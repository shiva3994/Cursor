#include <iostream>

void check_sensor(int distance) {
    if (distance < 10) {
        std::cout << "DANGER" << std::endl;
    } else {
        std::cout << "clear" << std::endl;
    }
}

int main() {
    check_sensor(5);
    check_sensor(20);
    return 0;
}

// g++ 7Functions.cpp -o 7Functions.exe; .\7Functions.exe