//
// Created by vst on 5/21/17.
//

#ifndef TEST_CLIMATE_ADAFRUIT_BME280_H
#define TEST_CLIMATE_ADAFRUIT_BME280_H

#include "Arduino.h"

class Adafruit_BME280 {
public:
    static float temperature;
    static float humidity;

    bool begin(uint8_t addr) {
        return true;
    }

    float readHumidity() {
        return humidity;
    }

    float readTemperature() {
        return temperature;
    }

    void setTemperature(float val) {
        temperature = val;
    }

    void setHumanity(float val) {
        humidity = val;
    }
};

#endif //TEST_CLIMATE_ADAFRUIT_BME280_H
