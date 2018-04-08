#include "HumidityController.hpp"

HumidityController *controller = new HumidityController();

void setup() {
    Serial.begin(9600);
    controller->setup();
}

void loop() {
    controller->loop(millis());
}
