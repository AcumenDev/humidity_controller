#include "Relays.hpp"
#include "DebugUtils.hpp"

Relays::Relays(uint8_t humidificationRelayPin, uint8_t heatingRelayPin, uint8_t coolingRelayPin,
               uint8_t ventilationRelayPin) {
    this->humidificationRelayPin = humidificationRelayPin;
    this->heatingRelayPin = heatingRelayPin;
    this->coolingRelayPin = coolingRelayPin;
    this->ventilationRelayPin = ventilationRelayPin;

    pinMode(humidificationRelayPin, OUTPUT);
    pinMode(heatingRelayPin, OUTPUT);
    pinMode(coolingRelayPin, OUTPUT);
    pinMode(ventilationRelayPin, OUTPUT);

    digitalWrite(humidificationRelayPin, HIGH);
    digitalWrite(heatingRelayPin, HIGH);
    digitalWrite(coolingRelayPin, HIGH);
    digitalWrite(ventilationRelayPin, HIGH);
}

void Relays::humidification(bool val) {
   // DEBUG_PRINTLN("hun "+val);
    digitalWrite(humidificationRelayPin, !val);
}

void Relays::cooling(bool val) {
    //DEBUG_PRINTLN("coo "+val);
    digitalWrite(coolingRelayPin, !val);
}

void Relays::heating(bool val) {
   // DEBUG_PRINTLN("hea "+val);
    digitalWrite(heatingRelayPin, !val);
}

void Relays::ventilation(bool val) {
    digitalWrite(ventilationRelayPin, !val);
}

void Relays::draining(bool val) {
    if (val > digitalRead(coolingRelayPin)) {
        digitalWrite(coolingRelayPin, !val);
    }
}
