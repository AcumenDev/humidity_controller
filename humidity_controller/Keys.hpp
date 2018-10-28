#ifndef Keys_h
#define Keys_h

#include "Values.hpp"
#include "Arduino.h"
#include "DebugUtils.hpp"
#include "AnalogButton.hpp"

class Keys {

    AnalogButton *analogButton;
public:
    Keys(uint8_t keysPin, AnalogButton *analogButton);

    void update(Values *values, unsigned long currentMillis);
};

#endif
