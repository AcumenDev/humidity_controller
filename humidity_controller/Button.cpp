#include "Button.hpp"

Button::Button(uint8_t buttonPin) {
	this->buttonPin = buttonPin;
}

Button::Button(uint8_t buttonPin, uint8_t minVal, uint8_t maxVal) {
	this->buttonPin = buttonPin;
	this->minVal = minVal;
	this->maxVal = maxVal;
	this->analog = true;
}

bool Button::readKey() {
	if (analog) {
		int analogValue = analogRead(buttonPin);
		return analogValue > minVal && analogValue < maxVal;
	} else {
		return (bool) digitalRead(buttonPin);
	}
}

void Button::update(unsigned long currentMillis) {
	bool reading = readKey();

	if (reading != lastButtonState) {
		lastDebounceTime = millis();
	}

	if ((millis() - lastDebounceTime) > debounceDelay) {
		buttonState = reading;
		lastDebounceTime = 0;
		readPresed = false;
	}

	lastButtonState = reading;

}

bool Button::isPressed() {
	if (buttonState) {
		readPresed = true;
		buttonState = false;
		return true;
	}
	return buttonState;
}
