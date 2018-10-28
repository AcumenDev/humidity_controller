#include "Keys.hpp"

Keys::Keys(uint8_t keysPin, AnalogButton *analogButton) {
    pinMode(keysPin, INPUT);
    this->analogButton = analogButton;
}


void Keys::update(Values *values, unsigned long currentMillis) {
    analogButton->update(currentMillis);
    int keyPres = analogButton->isPressed();
    switch (keyPres) {
        case BUTTON_UP: {
            Value *value = values->getClimatVal(TEMPERATURE);
            if (value->target < MAX_TARGET_TEMPERATURE) {
                value->target = value->target + 0.5;
            }
            break;
        }
        case BUTTON_DOWN: {
            Value *value = values->getClimatVal(TEMPERATURE);
            if (value->target > MIN_TARGET_TEMPERATURE) {
                value->target = value->target - 0.5;
            }
            break;
        }
        case BUTTON_LEFT: {
            Value *value = values->getClimatVal(HUMIDITY);
            if (value->target > MIN_TARGET_HUMIDITY) {
                value->target = value->target - 1;
            }
            break;
        }
        case BUTTON_RIGHT: {
            Value *value = values->getClimatVal(HUMIDITY);
            if (value->target < MAX_TARGET_HUMIDITY) {
                value->target = value->target + 1;
            }
            break;
        }
        default:
            break;
    }
}
