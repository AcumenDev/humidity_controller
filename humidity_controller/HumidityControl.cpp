#include "HumidityControl.hpp"

HumidityControl::HumidityControl(Relays *relays, int interval) :
		IntervalWorkerBase(interval) {
	this->relays = relays;
}

void HumidityControl::work(Values *values, unsigned long millis) {
	Value * value = values->getClimatVal(HUMIDITY);

	if (value->getCurrent() >= value->getTarget() + value->getGisteris()) {
		value->setActive(false);

	} else {
		value->setActive(value->getCurrent() < value->getTarget() - value->getGisteris());
	}

	relays->humidification(value->getActive());
}
