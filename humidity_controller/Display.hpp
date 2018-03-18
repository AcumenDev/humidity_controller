#ifndef DISPLAY_H
#define DISPLAY_H

#include <LiquidCrystal.h>
#include "Values.hpp"
#include "Arduino.h"
#include "inttypes.h"
#include "IntervalWorkerBase.hpp"

class Display: public IntervalWorkerBase {

	LiquidCrystal *lcd;
	int intervalChange;

public:
	Display(uint8_t rs, uint8_t enable, uint8_t d0, uint8_t d1, uint8_t d2,
			uint8_t d3, int intervalChange, int interval);

	void update(Values *values, unsigned long currentMillis);

private:

	void render(Values *values);
};

#endif //DISPLAY_H
