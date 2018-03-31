#ifndef BUTTON_HPP
#define BUTTON_HPP
#include "Values.hpp"
#include "Arduino.h"
#include "inttypes.h"

class Button {
private:
	unsigned long lastDebounceTime = 0;

	unsigned long debounceDelay = 50;

	bool buttonState = false;

	bool lastButtonState = false;

	int buttonPin = -1;

	uint8_t minVal = 0;
	uint8_t maxVal = 0;

	bool readPresed = false;

	bool readKey();

	bool analog = false;

public:
	Button(uint8_t buttonPin);
	Button(uint8_t buttonPin, uint8_t minVal, uint8_t maxVal);

	void update(unsigned long currentMillis);

	bool isPressed();
};



#endif
