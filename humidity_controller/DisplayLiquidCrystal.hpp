#ifndef TEST_DISPLAY_LIQUIDCRYSTAL_HPP
#define TEST_DISPLAY_LIQUIDCRYSTAL_HPP

#include "Display.hpp"

class DisplayLiquidCrystal : public Display {

    LiquidCrystal * liquidCrystal;

  public:

    DisplayLiquidCrystal(LiquidCrystal * liquidCrystal) {
      this->liquidCrystal = liquidCrystal;
    }

    void setCursor(int i, int i1) override {
      liquidCrystal->setCursor(i, i1);
    }

    void print(const char *value) override {
      liquidCrystal->print(value);

    }

    void print(const float &value)override {
      liquidCrystal->print(value);

    }
};


#endif //TEST_DISPLAY_LIQUIDCRYSTAL_HPP
