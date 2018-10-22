//
// Created by vst on 4/1/18.
//

#ifndef TEST_HUMIDITY_CONTROLLER_ONEWIRE_H
#define TEST_HUMIDITY_CONTROLLER_ONEWIRE_H


class OneWire{
public:
    OneWire(int){}

    bool search(unsigned char string[8]) {
        return false;
    }
};

#endif //TEST_HUMIDITY_CONTROLLER_ONEWIRE_H
