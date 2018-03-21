#ifndef Relays_h
#define Relays_h

#include "Arduino.h"
#include "inttypes.h"

class Relays {
    uint8_t humidificationRelayPin;
    uint8_t heatingRelayPin;
    uint8_t coolingRelayPin;
    uint8_t ventilationRelayPin;
public:
    Relays(uint8_t humidificationRelayPin, uint8_t heatingRelayPin, uint8_t coolingRelayPin,
           uint8_t ventilationRelayPin);

    void humidification(bool val);

    void heating(bool val);

    void cooling(bool val);

    void ventilation(bool val);

    void draining(bool val);


};

#endif
