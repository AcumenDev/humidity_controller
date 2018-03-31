//
// Created by vladimir on 12/18/16.
//

#ifndef TEST_CLIMATE_ARDUINO_H
#define TEST_CLIMATE_ARDUINO_H

#include <stdint.h>
#include <iostream>
#include <cmath>
#include <cfloat>
#include "HardwareSerial.hpp"
#include "../../humidity_controller/Config.hpp"


#define A0 22
#define A1 22
#define A2 22
#define A3 22
#define A4 22
#define A5 22


typedef uint8_t byte;
typedef bool boolean;
#define HIGH 0x1
#define LOW  0x0

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

unsigned long millis();

void delay(int);


int digitalRead(int pin);

void pinMode(uint8_t pin, uint8_t mode);

int digitalRead(uint8_t pin);

int analogRead(uint8_t pin);

void digitalWrite(uint8_t pin, uint8_t val);


char *dtostrf(double __val, signed char __width, unsigned char __prec, char *__s) ;

#endif //TEST_CLIMATE_ARDUINO_H
