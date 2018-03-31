#ifndef HARDWARE_SERIAL_HPP
#define HARDWARE_SERIAL_HPP

#include <iostream>

using namespace std;

class HardwareSerial {
public:
    void begin(unsigned long baud);
    size_t print(const char item[]);
    size_t print(char item) ;
    size_t print(int item);
    size_t print(double item);
    size_t print(long unsigned int);
    void flush();
    size_t println(const char[]);
    size_t println(int);
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