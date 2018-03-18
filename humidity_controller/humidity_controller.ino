#include "THSensors.hpp"
#include "Keys.hpp"
#include "Display.hpp"
#include "Config.hpp"
#include "Monitoring.hpp"

Values values;
THSensors *thSensors;
Keys *keys;
Display *display;
Monitoring *monitoring;

void setup() {
	Serial.begin(9600);
	values.loadFromEEprom();
	thSensors = new THSensors(5000);
	display = new Display(DISPLAY_RS_PIN, DISPLAY_ENABLE_PIN, DISPLAY_D0_PIN,
	DISPLAY_D1_PIN, DISPLAY_D2_PIN, DISPLAY_D3_PIN, 100, 2500);
	monitoring = new Monitoring(5 * 1000);
	keys = new Keys(BUTTON_SELECT_PIN, BUTTON_MINUS_PIN, BUTTON_PLUS_PIN);
}

void loop() {
	thSensors->update(&values, millis());
	keys->update(&values, millis());
	display->update(&values, millis());
	values.update(millis());
	monitoring->update(&values, millis());
}
