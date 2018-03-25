#include "Display.hpp"

Display::Display(uint8_t rs, uint8_t enable, uint8_t d0, uint8_t d1, uint8_t d2,
		uint8_t d3, int intervalChange, int interval) :
		IntervalWorkerBase(interval) {
	this->intervalChange = intervalChange;
	lcd = new LiquidCrystal(rs, enable, d0, d1, d2, d3);
	lcd->begin(16, 2);
}

void Display::update(Values *values, unsigned long currentMillis) {
	if (values->isAfterChange(currentMillis)) {
		if (!isWorkTime(currentMillis, intervalChange)) {
			return;
		}

	} else {
		if (!isWorkTime(currentMillis)) {
			return;
		}

		//values->changeTimeStamp = 0;
	}

	render(values);
}

void Display::render(Values *values) {
	lcd->setCursor(0, 0);
	lcd->print(" Temp: ");
	lcd->print(
			values->getClimatVal(TYPE_CLIMATE_VALUE::TEMPERATURE)->getCurrent());
	lcd->println(" C   ");
	lcd->setCursor(0, 1);
	lcd->print("Humidity: ");
	lcd->print(
			values->getClimatVal(TYPE_CLIMATE_VALUE::HUMIDITY)->getCurrent());
	lcd->println(" %    ");
}
