//============================================================================
// Name        : testAnalogButton.cpp
// Author      : cc
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;
static const int daySeconds = 86400;

int main() {





    cout << "StartTest" << endl; // prints !!!Hello World!!!

    bool state = true;
    unsigned long startTime = 0;
    unsigned long currentSeconds;
    unsigned long currentMillis = 0;
    startTime = 0;
    while (state) {
        if (currentMillis / 1000 >= daySeconds * 1) {
            break;
        }
        currentSeconds = static_cast<unsigned long>(
                duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count() / 1000);

        currentMillis += 1000;

       // analogButton->update(currentMillis);


    //    cout << analogButton->isPressed() << endl;

    }
    return 0;
}
