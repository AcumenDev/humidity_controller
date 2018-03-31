#ifndef Keys_h
#define Keys_h

#include "Values.hpp"
#include "Arduino.h"
#include "inttypes.h"
#include "DebugUtils.hpp"
#include "Menu.hpp"
#include "AnalogButton.hpp"

class Keys {

	AnalogButton* analogButton;
	Menu<LiquidCrystal> * menu;
public:
	Keys(uint8_t keysPin, Menu<LiquidCrystal> * menu);
	void update(Values *values, unsigned long currentMillis);
};

#endif
