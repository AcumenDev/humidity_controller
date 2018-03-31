//
// Created by vst on 5/27/17.
//

#ifndef TEST_CLIMATE_SERVO_H
#define TEST_CLIMATE_SERVO_H


class Servo {

    int value;

public:
    Servo() {

    }
    void attach(int i) {}

    void write(int value) { this->value = value; }

    void writeMicroseconds() {}

    int read() { return value; }

    void attached() {}

    void detach() {}
};

#endif //TEST_CLIMATE_SERVO_H
