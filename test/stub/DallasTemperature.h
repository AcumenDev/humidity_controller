//
// Created by vst on 4/1/18.
//

#ifndef TEST_HUMIDITY_CONTROLLER_DALLASTEMPERATURE_H
#define TEST_HUMIDITY_CONTROLLER_DALLASTEMPERATURE_H

#include "Arduino.h"
#include "OneWire.h"
class DallasTemperature{
public:
    DallasTemperature(OneWire* oneWire){}

    void  begin(){}

    void requestTemperatures() {

    }

    float getTempC(uint8_t *adr) {
        return 0;
    }
};
#endif //TEST_HUMIDITY_CONTROLLER_DALLASTEMPERATURE_H
