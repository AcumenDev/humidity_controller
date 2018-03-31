#ifndef ANALOGBUTTON_HPP_
#define ANALOGBUTTON_HPP_

#include "Arduino.h"
#include "inttypes.h"

struct Key {
    Key(unsigned int id, unsigned int minVal, unsigned int maxVal) {
        this->id = id;
        this->minVal = minVal;
        this->maxVal = maxVal;
    }

    unsigned int id;
    unsigned int minVal = 0;
    unsigned int maxVal = 0;
};

class AnalogButton {
private:
    unsigned long lastDebounceTime = 0;

    unsigned long debounceDelay = 50;

    int buttonState = -1;

    int lastButtonState;

    int buttonPin = -1;

    Key *keys;

    int size;

    bool readPresed = false;

    int readKey();

public:
    AnalogButton(uint8_t buttonPin, Key *keys, int size);

    void update(unsigned long currentMillis);

    int isPressed();
};

#endif /* ANALOGBUTTON_HPP_ */
