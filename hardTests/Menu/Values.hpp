#ifndef VALUES_HPP_
#define VALUES_HPP_

#include "Value.hpp"
#include "Arduino.h"
#include "Config.hpp"


enum TYPE_CLIMATE_VALUE {
	TEMPERATURE = 0, HUMIDITY = 1
};

class Values {
public:
	Values() {
		climateValues[TYPE_CLIMATE_VALUE::TEMPERATURE] = new Value(
		MIN_TARGET_TEMPERATURE, MAX_TARGET_TEMPERATURE,
		TEMPERATURE_GISTERIS);
		climateValues[TYPE_CLIMATE_VALUE::HUMIDITY] = new Value(
		MIN_TARGET_HUMIDITY, MAX_TARGET_HUMIDITY,
		HUMIDITY_GISTERIS);
	}
	unsigned long changeTimeStamp = 0;

	bool changed = false;

	unsigned int changeDelay = 1500;

	Value *climateValues[2];

	float wetT = 0;
//
//	void loadFromEEprom() {
//		target = (int) EEPROM.read(TARGET_HUMIDITY_EEPROM_ADR);
//	}
//
//	void saveToEEprom() {
//		EEPROM_writeAnything(TARGET_HUMIDITY_EEPROM_ADR, getTarget());
//	}
//
//
//
//	void setTarget(int target) {
//		if (target >= minTarget && target <= maxTarget) {
//			this->target = target;
//		}
//	}

	Value *getClimatVal(TYPE_CLIMATE_VALUE climateValue) {
		return climateValues[climateValue];
	}

	bool isAfterChange(unsigned long currentMillis) {
		return currentMillis - changeTimeStamp < changeDelay;
	}

	void update(unsigned long currentMillis) {
		if (!changed) {
			return;
		}

		if (currentMillis - changeTimeStamp > changeDelay) {
			//	saveToEEprom();
			changed = false;
		}
	}

	void plus(unsigned long currentMillis) {
//		if (target < maxTarget) {
//			target++;
//		}
		setTimestamp(currentMillis);
	}

	void minus(unsigned long currentMillis) {
//		if (target > minTarget) {
//			target--;
//		}
		setTimestamp(currentMillis);
	}

	void changeSelection(unsigned long currentMillis) {
		setTimestamp(currentMillis);
	}

private:
	void setTimestamp(unsigned long currentMillis) {
		changeTimeStamp = currentMillis;
		changed = true;
	}

};

#endif /* VALUES_HPP_ */
