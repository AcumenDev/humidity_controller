#include "HardwareSerial.hpp"

void HardwareSerial::begin(unsigned long baud) {
    cout.precision(2);
    cout << std::fixed;
}

size_t HardwareSerial::print(const char item[]) {
    cout << item;
}

size_t HardwareSerial::print(char item) {
    cout << item;
}

size_t HardwareSerial::print(int item) {
    cout << item;
}

size_t HardwareSerial::print(double item) {
    // cout.precision(4);
    cout << item;
}

void HardwareSerial::flush() {
    cout << std::flush;
}

size_t HardwareSerial::println(const char item[]) {
    cout << item << std::endl;
}

size_t HardwareSerial::print(unsigned long item) {
    cout << item;
}

size_t HardwareSerial::println(int i) {
    cout << i << std::endl;
}

size_t HardwareSerial::print(unsigned int i) {
    cout << i;
}

size_t HardwareSerial::print(unsigned char i, int) {
    cout << i;
}

size_t HardwareSerial::print(int i, int) {
    cout << i;
}

size_t HardwareSerial::print(unsigned int i, int) {
    cout << i;
}

size_t HardwareSerial::print(long i, int) {
    cout << i;
}
