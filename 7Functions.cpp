void check_sensor(int distance) {
    if (distance < 10) {
        std::cout << "DANGER" << std::endl;
    } else {
        std::cout << "clear" << std::endl;
    }
}

// g++ 7Functions.cpp -o 7Functions.exe; .\7Functions.exe