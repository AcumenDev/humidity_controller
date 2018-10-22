#include "DHT.h"

float DHT::temperature = 0;
float DHT::humidity = 0;

DHT::DHT(uint8_t pin, uint8_t type) {
}

void DHT::begin() {
}

float DHT::readHumidity(bool force) {
    return DHT::humidity;
}

float DHT::readTemperature(bool S, bool force) {
    return DHT::temperature;
}

void DHT::setTemp(float value) {
    DHT::temperature = value;
}

void DHT::setHumidity(float value) {
    DHT::humidity = value;
}
