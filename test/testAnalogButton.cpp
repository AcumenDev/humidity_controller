//============================================================================
// Name        : testAnalogButton.cpp
// Author      : cc
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <chrono>
#include <iostream>
#include "../humidity_controller/AnalogButton.hpp"

using namespace std;
using namespace std::chrono;
static const int daySeconds = 86400;

int main() {

    /*
     buttonPlus = new Button(keysPin, 100, 200);
     buttonMinus = new Button(keysPin, 200, 400);
     buttonSelect = new Button(keysPin, 600, 800);
     */

    Key keys[] = { Key(1, 100, 200), Key(2, 200, 400), Key(3, 600, 800) };

    AnalogButton* analogButton = new AnalogButton(1, keys, 3);

    cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

    bool state = true;
    unsigned long startTime = 0;
    unsigned long currentSeconds;
    unsigned long currentMillis = 0;
    startTime = 0;
    while (state) {
        if (currentMillis / 1000 >= daySeconds * 1) {
            break;
        }
        currentSeconds = duration_cast<milliseconds>(
                system_clock::now().time_since_epoch()).count() / 1000;

        currentMillis += 1000;

        analogButton->update(currentMillis);


        cout <<  analogButton->isPressed() << endl;

    }
    return 0;
}
