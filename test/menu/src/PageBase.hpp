//
// Created by vst on 10/15/17.
//

#ifndef TEST_CLIMATE_PAGE_BASE_HPP
#define TEST_CLIMATE_PAGE_BASE_HPP


#include "Display.hpp"

class PageBase {

public:
    PageBase() {
    }

    virtual void render(Display *display) {

    }

    //virtual void void changeEvent(T event) = 0;
    virtual const char *getName() const =0;

    virtual void up() {
    }

    virtual void down() {
    }

    virtual PageBase *enter() {
        return nullptr;
    }
};

#endif //TEST_CLIMATE_PAGE_HPP
