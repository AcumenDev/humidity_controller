#ifndef BUTTON_HPP
#define BUTTON_HPP
#include "Values.hpp"
#include "Arduino.h"
#include "inttypes.h"

class Button {
    unsigned long lastDebounceTime;
    unsigned long debounceDelay;

    bool buttonState;
    bool lastButtonState;

    byte buttonPin;
    bool readPresed;

  public:
    Button(byte buttonPin);

    void update(unsigned long currentMillis);
    bool isPressed();
};
#endif
