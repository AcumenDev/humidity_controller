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

Menu<Display> * buildMenu(Values *values, Display *display) {

	PageBase<Display> *tPages[] = { new PageValue<Display>("Gisteris",
			new FloatChanger(&(values->getClimatVal(TEMPERATURE)->gisteris), 0,
					10, 0.1)), new PageValue<Display>("Target",
			new FloatChanger(&values->getClimatVal(TEMPERATURE)->target, 0, 10,
					0.1)) };
	PageGroup<Display> *tGroup = new PageGroup<Display>("T", tPages, 2);

	PageBase<Display> *hPages[] = { new PageValue<Display>("Gisteris",
			new FloatChanger(&values->getClimatVal(HUMIDITY)->gisteris, 0, 10,
					0.1)), new PageValue<Display>("Target",
			new FloatChanger(&values->getClimatVal(HUMIDITY)->target, 0, 10,
					0.1)) };
	PageGroup<Display> *hGroup = new PageGroup<Display>("H", hPages, 2);

	PageBase<Display> *mainPages[] = { tGroup, hGroup };
	PageGroup<Display> *mainGroup = new PageGroup<Display>(mainPages, 3);

	return new Menu<Display>(display, 1, mainGroup);

}

Values *values;
THSensors *thSensors;
Keys *keys;
Display *display;
Monitoring *monitoring;
Relays *relays;
HumidityControl * humidityControl;

Menu<Display> * menu;

void setup() {

	Serial.begin(9600);
	values = new Values();
	//values.loadFromEEprom();
	relays = new Relays(HUMIDIFICATION_RELAY_PIN, HEATING_RELAY_PIN);
	thSensors = new THSensors(WET_SENSOR_ADR, DRY_SENSOR_ADR, TEMP_SENSOR_PIN,
			5000);
	display = new Display(DISPLAY_RS_PIN, DISPLAY_ENABLE_PIN, DISPLAY_D0_PIN,
	DISPLAY_D1_PIN, DISPLAY_D2_PIN, DISPLAY_D3_PIN, 100, 5000);
	monitoring = new Monitoring(5 * 1000);
	keys = new Keys(BUTTONS_PIN);

	humidityControl = new HumidityControl(relays, 5000);

	menu = buildMenu(values, display);
	delay(200);
}

void loop() {
	thSensors->update(values, millis());
	keys->update(values, millis());
	display->update(values, millis());
	values->update(millis());
	monitoring->update(values, millis());
	humidityControl->update(values, millis());
}
