#include <iostream>
// Iclude <iostream> — C++ needs you to "import" the input/output library first (Python has print built in).

int main() {
    // int main() { ... } — every C++ program needs a main() function as the entry point;
    // code can't just float at the top level like in Python.
    std::cout << "Hello world ! from C++" << std::endl;
    // std::cout << this is C++'s way of "printing" to the screen (cout = "character output").
    // The << arrows feed the text into it.
    // std::endl — adds a newline (like Python's automatic newline after print).
    return 0;
}   //return 0; — tells the operating system the program finished successfully.
    //Optional in Python, required in C++.

    //Run the program::
    //g++ L_main.cpp -o L_main.exe (g++ yourfilename.cpp -o yourfilename.exe)
    //.\L_main.exe (.\yourfilename.exe)