#include "AnalogButton.hpp"


AnalogButton::AnalogButton(uint8_t buttonPin, Key *keys, int size) {
    this->buttonPin = buttonPin;
    this->keys = keys;
    this->size = size;
    Serial.println("AnalogButton");
}

int AnalogButton::readKey() {

    int analogValue = analogRead(buttonPin);
    Serial.print("minval ");
    for (int i = 0; i < size; i++) {

        Serial.print("minval ");

        Serial.print(keys[i].minVal);
        Serial.print(" > ");
        Serial.print(analogValue);
        Serial.print(" < ");
        Serial.println(keys[i].maxVal);
        if (analogValue > keys[i].minVal && analogValue < keys[i].maxVal) {
            Serial.println("true");
            return keys[i].id;
        }else{
            Serial.println("false");
        }
    }

    return -1;

}

void AnalogButton::update(unsigned long currentMillis) {

    int reading = readKey();
    Serial.println(reading);

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

