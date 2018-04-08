//
// Created by vst on 10/15/17.
//

#ifndef TEST_CLIMATE_PAGE_VALUE_HPP
#define TEST_CLIMATE_PAGE_VALUE_HPP


#include "PageBase.hpp"
#include "Changer.hpp"


class PageValue : public PageBase {
private:
    Changer *changer;
    const char *name;
public:
    PageValue(const char *name, Changer *changer) {
        this->name = name;
        this->changer = changer;
    }

    const char *getName() const {
        return name;
    }


    virtual void render(LiquidCrystal *display) override {

        display->setCursor(0, 0);
        display->print(changer->getChars());
       // display->print(values->getClimatVal(TYPE_CLIMATE_VALUE::TEMPERATURE)->getCurrent());
        //   display->println(changer->getChars());
    }

    void up() override {
        changer->up();
    }

    void down() override {
        changer->down();
    }

};


#endif //TEST_CLIMATE_PAGE_HPP
