#ifndef VALUES_HPP_
#define VALUES_HPP_

#include "Arduino.h"
#include "Config.hpp"
#include "EEPROMUtils.hpp"

class Values {
public:
	unsigned long changeTimeStamp = 0;bool changed = false;

	unsigned int changeDelay = 1500;

	float dryT;
	float wetT;

	float humDyn;
	float humStat;

	int target;
	int maxTarget;
	int minTarget;

	int gisteris = 1;

	void loadFromEEprom() {
		target = (int) EEPROM.read(TARGET_HUMIDITY_EEPROM_ADR);
	}

	void saveToEEprom() {
		EEPROM_writeAnything(TARGET_HUMIDITY_EEPROM_ADR, getTarget());
	}

	int getTarget() {
		return target;
	}

	void setTarget(int target) {
		if (target >= minTarget && target <= maxTarget) {
			this->target = target;
		}
	}

	bool isAfterChange(unsigned long currentMillis) {
		return currentMillis - changeTimeStamp < changeDelay;
	}

	void update(unsigned long currentMillis) {
		if (!changed) {
			return;
		}

		if (currentMillis - changeTimeStamp > changeDelay) {
			saveToEEprom();
			changed = false;
		}
	}

	void plus(unsigned long currentMillis) {
		if (target < maxTarget) {
			target++;
		}
		setTimestamp(currentMillis);
	}

	void minus(unsigned long currentMillis) {
		if (target > minTarget) {
			target--;
		}
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
