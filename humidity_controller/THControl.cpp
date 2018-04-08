#include "THControl.hpp"

THControl::THControl(Relays *relays, int interval) :
        IntervalWorkerBase(interval) {
    this->relays = relays;
}

void THControl::work(Values *values, unsigned long millis) {
    humidity(values->getClimatVal(HUMIDITY));
    temperature(values->getClimatVal(TEMPERATURE));
}

void THControl::humidity(Value *value) {
    if (value->getCurrent() < value->getTarget() - value->getGisteris()) {
        value->setActive(true);
        relays->humidification(value->getActive());
        return;
    }

    if (value->getCurrent() >= value->getTarget()) {
        value->setActive(false);
        relays->humidification(value->getActive());
        return;
    }
}


void THControl::temperature(Value *value) {
    if (value->getCurrent() < value->getTarget() - value->getGisteris()) {
        value->setActive(true);
        relays->heating(value->getActive());
        return;
    }

    if (value->getCurrent() >= value->getTarget()) {
        value->setActive(false);
        relays->heating(value->getActive());
        return;
    }
}


