//
// Created by vladimir on 12/18/16.
//

#ifndef TEST_CLIMATE_DHT_H
#define TEST_CLIMATE_DHT_H

#include <cstdint>

#define DHT22 1

class DHT {
    static float temperature;
    static float humidity;
public:
    DHT(uint8_t pin, uint8_t type);

    void begin();

    float readTemperature(bool S = false, bool force = false);

    float readHumidity(bool force = false);

    void setTemp(float value);

    void setHumidity(float value);
};


#endif //TEST_CLIMATE_DHT_H
