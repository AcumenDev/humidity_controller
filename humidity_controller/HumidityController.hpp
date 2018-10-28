//
// Created by vst on 4/1/18.
//

#ifndef TEST_HUMIDITY_CONTROLLER_HUMIDITYCONTROLLER_HPP
#define TEST_HUMIDITY_CONTROLLER_HUMIDITYCONTROLLER_HPP

#include <LiquidCrystal.h>
#include "THSensors.hpp"
#include "Keys.hpp"
#include "Config.hpp"
#include "Monitoring.hpp"
#include "Relays.hpp"
#include "HomePage.hpp"
#include "THControl.hpp"

class HumidityController {
    Values *values;
    THSensors *thSensors;
    Keys *keys;
    Monitoring *monitoring;
    Relays *relays;
    THControl *thControl;
    AnalogButton *analogButton;
    HomePage * homePage;

public:
    HumidityController() {}

    void setup();

    void loop(unsigned long currentMillis);
};


#endif //TEST_HUMIDITY_CONTROLLER_HUMIDITYCONTROLLER_HPP
