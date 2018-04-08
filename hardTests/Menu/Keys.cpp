#include <LiquidCrystal.h>
#include "Keys.hpp"

Keys::Keys(uint8_t keysPin, AnalogButton *analogButton, Menu<LiquidCrystal> *menu) {
    pinMode(keysPin, INPUT);
    /*
     buttonPlus = new Button(keysPin, 100, 200);
     buttonMinus = new Button(keysPin, 200, 400);
     buttonSelect = new Button(keysPin, 600, 800);
     */


   // DEBUG_PRINT("Keys");
    this->analogButton = analogButton;

    this->menu = menu;
}

void Keys::update(Values *values, unsigned long currentMillis) {
    analogButton->update(currentMillis);

    int keyPres = analogButton->isPressed();

 //   DEBUG_PRINTLN(keyPres);
    switch (keyPres) {
        case 1:
            //DEBUG_PRINT("+")
            menu->up();
            break;
        case 2:
            //DEBUG_PRINT("-")
            menu->down();
            break;
        case 3:
            //DEBUG_PRINT("sel")
            menu->enter();
            break;
        default:
            break;
    }

}
