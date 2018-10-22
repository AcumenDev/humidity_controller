//
// Created by vst on 10/22/17.
//

#include "FloatChanger.hpp"
#include <stdlib.h>
#include <Arduino.h>
#include <cstring>

FloatChanger::FloatChanger(float *value, float min, float max, float step) {
    this->value = value;
    this->min = min;
    this->max = max;
    this->step = step;
}

const char *FloatChanger::getChars() {
    char buf[34];
  //  memset(buf, 0, 34);
    return dtostrf(*value, 2, 2, buf);
}

void FloatChanger::up() {
    if (*value < max) {
        *value += step;
    }
}

void FloatChanger::down() {
    if (*value > min) {
        *value -= step;
    }
}