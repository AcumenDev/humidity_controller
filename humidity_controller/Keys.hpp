#ifndef Keys_h
#define Keys_h

#include "Values.hpp"
#include "Arduino.h"
#include "DebugUtils.hpp"
#include "Menu.hpp"
#include "AnalogButton.hpp"

class Keys {

    AnalogButton *analogButton;
    Menu *menu;
public:
    Keys(uint8_t keysPin, AnalogButton *analogButton, Menu *menu);

    void update(Values *values, unsigned long currentMillis);
};

#endif
