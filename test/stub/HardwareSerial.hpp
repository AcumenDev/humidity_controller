#ifndef HARDWARE_SERIAL_HPP
#define HARDWARE_SERIAL_HPP

#include <iostream>
#include "Arduino.h"


#define DEC 10
#define HEX 16
#define OCT 8
#ifdef BIN // Prevent warnings if BIN is previously defined in "iotnx4.h" or similar
#undef BIN
#endif
#define BIN 2

using namespace std;

class HardwareSerial {
public:
    void begin(unsigned long baud);
    size_t print(const char item[]);
    size_t print(char item) ;
    size_t print(int item);
    size_t print(double item);
    size_t print(long unsigned int);
    size_t print(unsigned int);
    void flush();
    size_t println(const char[]);
    size_t println(int);



    size_t print(unsigned char i , int );
    size_t print(int i , int );
    size_t print(unsigned int i, int );
    size_t print(long i, int );
    size_t print(unsigned long i, int);


/*    size_t println(const __FlashStringHelper *);
    size_t println(const String &s);
    size_t println(const char[]);
    size_t println(char);
    size_t println(unsigned char, int = DEC);

    size_t println(unsigned int, int = DEC);
    size_t println(long, int = DEC);
    size_t println(unsigned long, int = DEC);
    size_t println(double, int = 2);
    size_t println(const Printable&);
    size_t println(void);*/

    //  print
};

static HardwareSerial Serial;

#endif