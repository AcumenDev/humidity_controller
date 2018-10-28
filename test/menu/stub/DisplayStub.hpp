//
// Created by vladimir on 10/22/18.
//

#ifndef TEST_HUMIDITY_CONTROLLER_DISPLAYSTUB_HPP
#define TEST_HUMIDITY_CONTROLLER_DISPLAYSTUB_HPP


#include "../src/Display.hpp"
#include <iostream>

class DisplayStub : public Display {
public:
    void print(const char *value) override {
        std::cout << value;
    }

    void setCursor(int i, int i1) override {
        std::cout << std::endl;
    }

    void print(const float &value) override {
        std::cout << value;
    }
};

#endif //TEST_HUMIDITY_CONTROLLER_DISPLAYSTUB_HPP
