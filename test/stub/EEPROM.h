//
// Created by vladimir on 12/18/16.
//

#ifndef TEST_CLIMATE_EEPROM_H
#define TEST_CLIMATE_EEPROM_H

#include "Arduino.h"

struct Eeprom {
public:
    byte read(int address) { return 0; }

    void update(int address, byte value) { }

    virtual ~Eeprom() { }


    Eeprom() { }
};
static Eeprom EEPROM;
#endif //TEST_CLIMATE_EEPROM_H
