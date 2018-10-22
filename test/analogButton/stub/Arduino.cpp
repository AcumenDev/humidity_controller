#include "Arduino.h"


bool pins[20];
unsigned int __heap_start;
void *__brkval;


unsigned long millis() {
    return 0;
}

void delay(int){

}


int digitalRead(int pin) {
    return pins[pin];
}

void pinMode(uint8_t pin, uint8_t mode) {

}

int digitalRead(uint8_t pin) {
    return pins[pin];
}



int analogRead(uint8_t pin){

    return 205;
}



void digitalWrite(uint8_t pin, uint8_t val) {
    pins[pin] = val;
}

char *dtostrf(double __val, signed char __width, unsigned char __prec, char *__s) {
    // char array[33];
    sprintf(__s, "%f", __val);
    return __s;
}