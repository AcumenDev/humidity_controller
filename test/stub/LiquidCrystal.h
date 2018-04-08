//
// Created by vst on 3/31/18.
//

#ifndef TEST_HUMIDITY_CONTROLLER_LIQUIDCRYSTAL_H
#define TEST_HUMIDITY_CONTROLLER_LIQUIDCRYSTAL_H

#include "HardwareSerial.hpp"

class LiquidCrystal : public HardwareSerial {
public:
    LiquidCrystal(int, int, int, int, int, int) {}

    void begin(int, int) {

    }


    void setCursor(int, int) {

    }
};


#endif //TEST_HUMIDITY_CONTROLLER_LIQUIDCRYSTAL_H
