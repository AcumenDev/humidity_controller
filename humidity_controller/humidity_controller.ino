#include <LiquidCrystal.h>
#include "THSensors.hpp"
#include "Keys.hpp"
#include "Display.hpp"
#include "Config.hpp"
#include "Monitoring.hpp"
#include "Relays.hpp"
#include "HumidityControl.hpp"

#include "Menu.hpp"
#include "PageGroup.hpp"
#include "PageValue.hpp"
#include "FloatChanger.hpp"
#include "HomePage.hpp"

Menu<LiquidCrystal> * buildMenu(Values *values, LiquidCrystal *display) {

	PageBase<LiquidCrystal> *tPages[] = { new PageValue<LiquidCrystal>(
			"Gisteris",
			new FloatChanger(&(values->getClimatVal(TEMPERATURE)->gisteris), 0,
					10, 0.1)), new PageValue<LiquidCrystal>("Target",
			new FloatChanger(&values->getClimatVal(TEMPERATURE)->target, 0, 10,
					0.1)) };
	PageGroup<LiquidCrystal> *tGroup = new PageGroup<LiquidCrystal>("T", tPages,
			2);

	PageBase<LiquidCrystal> *hPages[] = { new PageValue<LiquidCrystal>(
			"Gisteris",
			new FloatChanger(&values->getClimatVal(HUMIDITY)->gisteris, 0, 10,
					0.1)), new PageValue<LiquidCrystal>("Target",
			new FloatChanger(&values->getClimatVal(HUMIDITY)->target, 0, 10,
					0.1)) };
	PageGroup<LiquidCrystal> *hGroup = new PageGroup<LiquidCrystal>("H", hPages,
			2);

	PageBase<LiquidCrystal> *mainPages[] = { tGroup, hGroup };
	PageGroup<LiquidCrystal> *mainGroup = new PageGroup<LiquidCrystal>(
			mainPages, 3);

	return new Menu<LiquidCrystal>(display, 1, mainGroup,
			new HomePage<LiquidCrystal>(values));

}

Values *values;
THSensors *thSensors;
Keys *keys;
//Display *display;
Monitoring *monitoring;
Relays *relays;
HumidityControl * humidityControl;

Menu<LiquidCrystal> * menu;

void setup() {

	LiquidCrystal * lcd = new LiquidCrystal(DISPLAY_RS_PIN, DISPLAY_ENABLE_PIN,
	DISPLAY_D0_PIN,
	DISPLAY_D1_PIN, DISPLAY_D2_PIN, DISPLAY_D3_PIN);
	lcd->begin(16, 2);

	Serial.begin(9600);
	values = new Values();
	//values.loadFromEEprom();
	relays = new Relays(HUMIDIFICATION_RELAY_PIN, HEATING_RELAY_PIN);
	thSensors = new THSensors(WET_SENSOR_ADR, DRY_SENSOR_ADR, TEMP_SENSOR_PIN,
			5000);
	//display = new Display(DISPLAY_RS_PIN, DISPLAY_ENABLE_PIN, DISPLAY_D0_PIN,	DISPLAY_D1_PIN, DISPLAY_D2_PIN, DISPLAY_D3_PIN, 100, 5000);
	monitoring = new Monitoring(5 * 1000);
	keys = new Keys(BUTTONS_PIN, menu);

	humidityControl = new HumidityControl(relays, 5000);

	menu = buildMenu(values, lcd);
	delay(200);
}

void loop() {
	menu->update(values, millis());
	thSensors->update(values, millis());
	keys->update(values, millis());
	//display->update(values, millis());
	values->update(millis());
	monitoring->update(values, millis());
	humidityControl->update(values, millis());
}
