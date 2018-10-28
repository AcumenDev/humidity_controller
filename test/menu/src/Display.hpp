//
// Created by vladimir on 10/22/18.
//

#ifndef TEST_HUMIDITY_CONTROLLER_DISPLAY_HPP
#define TEST_HUMIDITY_CONTROLLER_DISPLAY_HPP


class Display {


public:
    virtual void setCursor(int i, int i1) = 0;

    virtual void print(const char *value) = 0;

    virtual void print(const float &value) = 0;
};


#endif //TEST_HUMIDITY_CONTROLLER_DISPLAY_HPP
