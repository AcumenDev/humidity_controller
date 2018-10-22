//
// Created by vst on 10/15/17.
//

#ifndef TEST_CLIMATE_PAGEGROUP_HPP
#define TEST_CLIMATE_PAGEGROUP_HPP

#include "PageBase.hpp"
#include "Arduino.h"


class PageGroup : public PageBase {
private:
    PageBase **pages;
    uint8_t size;
    uint8_t current = 0;
    const char *name;
public:

    PageGroup(PageBase **pages, uint8_t size) {
        this->pages = pages;
        this->size = size;
    }

    PageGroup(const char *name, PageBase **pages, uint8_t size) {
        this->name = name;
        this->pages = pages;
        this->size = size;
    }

    const char *getName() const {
        return name;
    }


    const PageBase *getCurrentPage() {
        return pages[current];
    }

    void render(Display *display) {
      //  Serial.print("PageGroup ");

      //  Serial.print(name);
       // Serial.println(" render");
        // Serial.println(pages);
       // Serial.println(current);
        //delay(100);
       // Serial.println((uint64_t) pages[current]);
       // Serial.println(pages[current]->getName());


         display->setCursor(0, 0);
         display->print(pages[current]->getName());
    }

    void up() {
        if (current >= size - 1) {
            current = 0;
        } else {
            current++;
        }
    }

    void down() {
        if (current <= 0) {
            current = size - 1;
        } else {
            current--;
        }
    }

    PageBase *enter() {
        Serial.print("[PageGroup ");
        Serial.print(current);
        Serial.println(" enter]");

        return pages[current];
    }
};

#endif //TEST_CLIMATE_PAGEGROUP_HPP
