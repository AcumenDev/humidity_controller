#ifndef Keys_h
#define Keys_h

#include "Values.hpp"
#include "Arduino.h"
#include "inttypes.h"
#include "Button.hpp"
#include "DebugUtils.hpp"

class Keys {
	Button *buttonSelect;
	Button *buttonPlus;
	Button *buttonMinus;
public:
	Keys(uint8_t keysPin);
	void update(Values *values, unsigned long currentMillis);
};

#endif
