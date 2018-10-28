//
// Created by vladimir on 12/18/16.
//

#include "LedControl.h"

LedControl::LedControl(int dataPin, int clkPin, int csPin, int numDevices) {
}

void LedControl::clearDisplay(int addr) { }

void LedControl::setDigit(int addr, int digit, byte value, boolean dp) { }

void LedControl::setIntensity(int addr, int intensity) { }

void LedControl::setScanLimit(int addr, int limit) { }

void LedControl::shutdown(int addr, bool status) { }