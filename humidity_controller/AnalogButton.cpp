#include "AnalogButton.hpp"

AnalogButton::AnalogButton(uint8_t buttonPin, Key* keys, int size) {
	this->buttonPin = buttonPin;
	this->keys = keys;
	this->size = size;
}

int AnalogButton::readKey() {

	int analogValue = analogRead(buttonPin);

	for (int i = 0; i < size; i++) {
		if (analogValue > keys[i].minVal && analogValue < keys[i].maxVal)
			return keys[i].id;
	}

	return -1;

}

void AnalogButton::update(unsigned long currentMillis) {
	int reading = readKey();

	if (reading != lastButtonState) {
		lastDebounceTime = currentMillis;
	}

	if ((currentMillis - lastDebounceTime) > debounceDelay) {
		buttonState = reading;
		lastDebounceTime = 0;
		readPresed = false;
	}

	lastButtonState = reading;

}

int AnalogButton::isPressed() {
	if (buttonState != -1) {
		readPresed = true;
		int state = buttonState;
		buttonState = -1;
		return state;
	}
	return -1;
}

