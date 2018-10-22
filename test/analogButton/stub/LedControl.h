//ledControl
// Created by vladimir on 12/18/16.
//

#ifndef TEST_CLIMATE_LEDCONTROL_H
#define TEST_CLIMATE_LEDCONTROL_H


#include "Arduino.h"

class LedControl {
public:
    LedControl(int dataPin, int clkPin, int csPin, int numDevices = 1);

    void shutdown(int addr, bool status);

    void setScanLimit(int addr, int limit);

    void setIntensity(int addr, int intensity);

    void clearDisplay(int addr);

    void setDigit(int addr, int digit, byte value, boolean dp);

};


#endif //TEST_CLIMATE_LEDCONTROL_H
