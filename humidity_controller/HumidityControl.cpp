#include "HumidityControl.hpp"

HumidityControl::HumidityControl(int interval) :
		IntervalWorkerBase(interval) {
}

void HumidityControl::work(Values *values, unsigned long millis) {
	Value * value = &(values->humidity);

	if (value->value >= value->target + value->gisteris) {
		value->active = false;
	} else {
		value->active = value->value < value->target - value->gisteris;
	}
}
