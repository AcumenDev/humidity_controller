#include <LiquidCrystal.h>
#include "Keys.hpp"

Keys::Keys(uint8_t keysPin, AnalogButton *analogButton, Menu *menu) {
    pinMode(keysPin, INPUT);
    this->analogButton = analogButton;
    this->menu = menu;
}

void Keys::update(Values *values, unsigned long currentMillis) {
    analogButton->update(currentMillis);
    int keyPres = analogButton->isPressed();
    switch (keyPres) {
        case 1:
            menu->up();
            break;
        case 2:
            menu->down();
            break;
        case 3:
            menu->enter();
            break;
        default:
            break;
    }
}
