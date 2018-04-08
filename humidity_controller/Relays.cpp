#include "Relays.hpp"
#include "DebugUtils.hpp"

Relays::Relays(uint8_t humidificationRelayPin, uint8_t heatingRelayPin) {
    this->humidificationRelayPin = humidificationRelayPin;
    this->heatingRelayPin = heatingRelayPin;

    pinMode(humidificationRelayPin, OUTPUT);
    pinMode(heatingRelayPin, OUTPUT);

    digitalWrite(humidificationRelayPin, HIGH);
    digitalWrite(heatingRelayPin, HIGH);
}

void Relays::humidification(bool val) {
   // DEBUG_PRINTLN("hun "+val);
    digitalWrite(humidificationRelayPin, !val);
}


void Relays::heating(bool val) {
   // DEBUG_PRINTLN("hea "+val);
    digitalWrite(heatingRelayPin, !val);
}
