//
// Created by vst on 10/22/17.
//

#ifndef TEST_CLIMATE_CHANGER_HPP
#define TEST_CLIMATE_CHANGER_HPP


class  Changer {

public:
    virtual const char *getChars() =0;

    virtual void up() =0;

    virtual void down()=0;
};


#endif //TEST_CLIMATE_CHANGER_HPP
