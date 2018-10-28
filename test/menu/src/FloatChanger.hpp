//
// Created by vst on 10/22/17.
//

#ifndef TEST_CLIMATE_FLOATCHANGER_HPP
#define TEST_CLIMATE_FLOATCHANGER_HPP


#include "Changer.hpp"

class FloatChanger : public Changer {
    float *value;
    float min;
    float max;
    float step;
public:
    FloatChanger(float *value, float min, float max, float step);

    const char *getChars() override;

    void up() override;

    void down() override;

};


#endif //TEST_CLIMATE_FLOATCHANGER_HPP
