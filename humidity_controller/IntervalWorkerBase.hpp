#ifndef INTERVAL_WORKER_BASE_HPP
#define INTERVAL_WORKER_BASE_HPP

#include "TimeUtils.hpp"
#include "Values.hpp"

class IntervalWorkerBase {

    unsigned long _prev_ms = 0;
    int _interval = 0;

public:
    IntervalWorkerBase(int interval);

    virtual void work(Values *values, unsigned long currentMillis) {};

    bool isWorkTime(unsigned long currentMillis);

    bool isWorkTime(unsigned long currentMillis, int interval);

    virtual void update(Values *values, unsigned long currentMillis);
};

#endif
