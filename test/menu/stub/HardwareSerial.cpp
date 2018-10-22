#include "HardwareSerial.hpp"

void HardwareSerial::begin(unsigned long baud) {
    cout.precision(2);
    cout << std::fixed;
}

size_t HardwareSerial::print(const char item[]) {
    cout << item;
    return 0;
}

size_t HardwareSerial::print(char item) {
    cout << item;
    return 0;
}

size_t HardwareSerial::print(int item) {
    cout << item;
    return 0;
}

size_t HardwareSerial::print(double item) {
    // cout.precision(4);
    cout << item;
    return 0;
}

void HardwareSerial::flush() {
    cout << std::flush;

}

size_t HardwareSerial::println(const char item[]) {
    cout << item << std::endl;
    return 0;
}

size_t HardwareSerial::print(unsigned long item) {
    cout << item;
    return 0;
}

size_t HardwareSerial::println(int i) {
    std::cout << i << std::endl;
    return 0;
}

size_t HardwareSerial::print(unsigned int i) {
    cout << i;
    return 0;
}

size_t HardwareSerial::print(unsigned char i, int) {
    cout << i;
    return 0;
}

size_t HardwareSerial::print(int i, int) {
    cout << i;
    return 0;
}

size_t HardwareSerial::print(unsigned int i, int) {
    cout << i;
    return 0;
}

size_t HardwareSerial::print(long i, int) {
    cout << i;
    return 0;
}
