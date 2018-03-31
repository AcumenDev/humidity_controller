#include <LiquidCrystal.h>
#include "Keys.hpp"

Keys::Keys(uint8_t keysPin, Menu<LiquidCrystal> * menu) {
	pinMode(keysPin, INPUT_PULLUP);
	/*
	 buttonPlus = new Button(keysPin, 100, 200);
	 buttonMinus = new Button(keysPin, 200, 400);
	 buttonSelect = new Button(keysPin, 600, 800);
	 */

	Key keys[] = { Key(1, 100, 200), Key(2, 200, 400), Key(3, 600, 800) };

	analogButton = new AnalogButton(keysPin, keys, 3);

	this->menu = menu;
}

void Keys::update(Values *values, unsigned long currentMillis) {
	/*	buttonSelect->update(currentMillis);
	 buttonPlus->update(currentMillis);
	 buttonMinus->update(currentMillis);

	 DEBUG_PRINTLN(analogRead(A0));
	 if (buttonSelect->isPressed()) {
	 // Utils::log("sel");
	 DEBUG_PRINT("sel");
	 //	values->changeSelection(currentMillis);
	 menu->enter();
	 }

	 if (buttonMinus->isPressed()) {
	 DEBUG_PRINT("-");
	 //values->minus(currentMillis);
	 menu->down();
	 }

	 if (buttonPlus->isPressed()) {
	 DEBUG_PRINT("+");
	 //	values->plus(currentMillis);
	 menu->up();
	 }*/

	analogButton->update(currentMillis);

	int keyPres = analogButton->isPressed();
	DEBUG_PRINTLN(analogRead(A0));
	DEBUG_PRINTLN(keyPres);
	switch (keyPres) {
	case 1:
		DEBUG_PRINT("+")
		menu->up();
		break;
	case 2:
		DEBUG_PRINT("-")
		menu->down();
		break;
	case 3:
		DEBUG_PRINT("sel")
		menu->enter();
		break;
	default:
		break;
	}

}
