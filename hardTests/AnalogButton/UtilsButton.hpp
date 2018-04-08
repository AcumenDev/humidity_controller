//
// Created by vst on 4/1/18.
//

#ifndef TEST_HUMIDITY_CONTROLLER_UTILSBUTTON_HPP
#define TEST_HUMIDITY_CONTROLLER_UTILSBUTTON_HPP

class Key {
public:
    Key(unsigned int id, unsigned int minVal, unsigned int maxVal) {
        this->id = id;
        this->minVal = minVal;
        this->maxVal = maxVal;
    }

    unsigned int id;
    unsigned int minVal = 0;
    unsigned int maxVal = 0;
};

#endif //TEST_HUMIDITY_CONTROLLER_UTILSBUTTON_HPP
