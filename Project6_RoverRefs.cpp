// This project shows C++ references (&) with a small rover: functions must change the real battery, 
// heading, and speed in main, not copies.

// What it does
// The rover starts at 10% battery, heading 90° (east), speed 1.5 m/s. Then:

// chargeRobot — adds 20% (caps at 100)
// turnLeft — subtracts 90° (wraps below 0 by adding 360)
// stop — sets speed to 0
// It prints Before and After so you can see main’s variables actually changed.

// Expected result: battery 30%, heading 0° (north), speed 0.

// What you are learning
// Each parameter is a reference (int &battery, int &heading, double &speed). 
// That is a second name for the original variable. Without &, the rover in main would stay 10 / 90 / 1.5.

#include <iostream>

// Changes the ORIGINAL battery (like plugging in a charger)
void chargeRobot(int &battery) {
    battery = battery + 20;
    if (battery > 100) {
        battery = 100;   // cannot go over 100%
    }
}

// Motors change the ORIGINAL heading (degrees)
void turnLeft(int &heading) {
    heading = heading - 90;
    if (heading < 0) {
        heading = heading + 360;
    }
}

// Brakes change the ORIGINAL speed
void stop(double &speed) {
    speed = 0.0;
}

int main() {
    int battery = 10;      // %
    int heading = 90;      // facing east
    double speed = 1.5;    // m/s

    std::cout << "Before  battery=" << battery
              << "%  heading=" << heading
              << "  speed=" << speed << "\n";

    chargeRobot(battery);  // rover_battery-style: same object, not a copy
    turnLeft(heading);
    stop(speed);

    std::cout << "After   battery=" << battery
              << "%  heading=" << heading
              << "  speed=" << speed << "\n";

    return 0;
}

// g++ Project6_RoverRefs.cpp -o Project6_RoverRefs.exe; .\Project6_RoverRefs.exe