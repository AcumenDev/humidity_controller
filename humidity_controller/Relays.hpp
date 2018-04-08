#ifndef Relays_h
#define Relays_h

#include "Arduino.h"
#include "inttypes.h"

class Relays {
private:
	uint8_t humidificationRelayPin;
	uint8_t heatingRelayPin;
public:
	Relays(uint8_t humidificationRelayPin, uint8_t heatingRelayPin);

	void humidification(bool val);

	void heating(bool val);
};

#endif
