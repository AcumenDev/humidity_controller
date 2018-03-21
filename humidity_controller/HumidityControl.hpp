#ifndef TEST_CLIMATE_HUMIDITYCONTROL_HPP
#define TEST_CLIMATE_HUMIDITYCONTROL_HPP

#include "Values.hpp"
#include "Relays.hpp"
#include "IntervalWorkerBase.hpp"

class HumidityControl : public IntervalWorkerBase {
public:
    HumidityControl(int interval);

    void work(Values *values, unsigned long millis) override;
};

#endif
