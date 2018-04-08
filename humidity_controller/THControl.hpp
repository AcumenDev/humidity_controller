#ifndef TEST_CLIMATE_HUMIDITYCONTROL_HPP
#define TEST_CLIMATE_HUMIDITYCONTROL_HPP

#include "Values.hpp"
#include "Relays.hpp"
#include "IntervalWorkerBase.hpp"

class THControl: public IntervalWorkerBase {
private:
	Relays *relays;


	void temperature(Value * value);
	void humidity(Value * value);

public:
	THControl(Relays *relays, int interval);

	void work(Values *values, unsigned long millis) override;
};

#endif
