
#include "HumidityController.hpp"


Menu<LiquidCrystal> *HumidityController::buildMenu(Values *values, LiquidCrystal *display) {

    PageBase<LiquidCrystal> *tPages[] = {
            new PageValue<LiquidCrystal>("Gisteris",
                                         new FloatChanger(&(values->getClimatVal(TEMPERATURE)->gisteris), 0, 10, 0.1)),
            new PageValue<LiquidCrystal>("Target",
                                         new FloatChanger(&values->getClimatVal(TEMPERATURE)->target, 0, 10, 0.1))};


    auto *tGroup = new PageGroup<LiquidCrystal>("T", tPages, 2);

    PageBase<LiquidCrystal> *hPages[] = {
            new PageValue<LiquidCrystal>("Gisteris",
                                         new FloatChanger(&values->getClimatVal(HUMIDITY)->gisteris, 0, 10, 0.1)),
            new PageValue<LiquidCrystal>("Target",
                                         new FloatChanger(&values->getClimatVal(HUMIDITY)->target, 0, 10, 0.1))
    };

    auto *hGroup = new PageGroup<LiquidCrystal>("H", hPages, 2);

    PageBase<LiquidCrystal> *mainPages[] = {tGroup, hGroup};
    auto *mainGroup = new PageGroup<LiquidCrystal>(mainPages, 3);

    return new Menu<LiquidCrystal>(display, 1, mainGroup, new HomePage<LiquidCrystal>(values));

}


void HumidityController::setup() {
    Serial.begin(9600);


    Key keysDef[] = {Key(1, 100, 200), Key(2, 200, 400), Key(3, 600, 800)};
    analogButton = new AnalogButton(BUTTONS_PIN, keysDef, 3);


    LiquidCrystal *lcd = new LiquidCrystal(DISPLAY_RS_PIN, DISPLAY_ENABLE_PIN, DISPLAY_D0_PIN, DISPLAY_D1_PIN,
                                           DISPLAY_D2_PIN, DISPLAY_D3_PIN);
    lcd->begin(16, 2);


    values = new Values();
    //values.loadFromEEprom();
    relays = new Relays(HUMIDIFICATION_RELAY_PIN, HEATING_RELAY_PIN);
    thSensors = new THSensors(WET_SENSOR_ADR, DRY_SENSOR_ADR, TEMP_SENSOR_PIN, 5000);
    //display = new Display(DISPLAY_RS_PIN, DISPLAY_ENABLE_PIN, DISPLAY_D0_PIN,	DISPLAY_D1_PIN, DISPLAY_D2_PIN, DISPLAY_D3_PIN, 100, 5000);
    monitoring = new Monitoring(5 * 1000);
    keys = new Keys(BUTTONS_PIN, analogButton, menu);

    humidityControl = new HumidityControl(relays, 5000);

    menu = buildMenu(values, lcd);
    delay(200);
}

void HumidityController::loop(unsigned long currentMillis) {
    menu->update(values, millis());
    thSensors->update(values, millis());
    keys->update(values, millis());
    //display->update(values, millis());
    values->update(millis());
    monitoring->update(values, millis());
    humidityControl->update(values, millis());
}
    