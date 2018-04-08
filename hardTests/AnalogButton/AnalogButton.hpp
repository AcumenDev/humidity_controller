#ifndef ANALOGBUTTON_HPP_
#define ANALOGBUTTON_HPP_

#include "Arduino.h"
#include "UtilsButton.hpp"



class AnalogButton {
private:
    unsigned long lastDebounceTime = 0;

    unsigned long debounceDelay = 50;

    int buttonState = -1;

    int lastButtonState = -1;

    uint8_t buttonPin;

    Key *keys;

    int size;

    bool presed = false;

    int readKey();

public:
    AnalogButton(uint8_t buttonPin, Key *keys, int size);

    void update(unsigned long currentMillis);

    int isPressed();
};

#endif /* ANALOGBUTTON_HPP_ */
