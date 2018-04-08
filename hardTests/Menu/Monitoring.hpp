#ifndef TEST_CLIMATE_MONITORING_HPP
#define TEST_CLIMATE_MONITORING_HPP

#include "IntervalWorkerBase.hpp"
#include "Values.hpp"

class Monitoring: public IntervalWorkerBase {
public:
	Monitoring(int interval);
private:
	void work(Values *values, unsigned long currentMillis) override;
};

#endif //TEST_CLIMATE_MONITORING_HPP
