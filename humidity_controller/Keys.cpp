#include "Keys.hpp"

Keys::Keys(uint8_t keysPin) {
//	pinMode(keysPin, INPUT_PULLUP);
	buttonPlus = new Button(keysPin, 100, 200);
	buttonMinus = new Button(keysPin, 200, 400);
	buttonSelect = new Button(keysPin, 600, 800);
}

void Keys::update(Values *values, unsigned long currentMillis) {
	buttonSelect->update(currentMillis);
	buttonPlus->update(currentMillis);
	buttonMinus->update(currentMillis);
	DEBUG_PRINTLN(analogRead(A0));
	if (buttonSelect->isPressed()) {
		// Utils::log("sel");
		DEBUG_PRINT("sel");
		values->changeSelection(currentMillis);
	}

	if (buttonMinus->isPressed()) {
		DEBUG_PRINT("-");
		values->minus(currentMillis);
	}

	if (buttonPlus->isPressed()) {
		DEBUG_PRINT("+");
		values->plus(currentMillis);
	}
}
