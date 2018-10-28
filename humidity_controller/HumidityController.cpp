
#include "HumidityController.hpp"


void HumidityController::setup() {
    Serial.begin(9600);




    Key keysDef[] = {
            Key(BUTTON_UP, 100, 200),
            Key(BUTTON_DOWN, 200, 400),
            Key(BUTTON_LEFT, 400, 600),
            Key(BUTTON_RIGHT, 0, 100)};
    analogButton = new AnalogButton(BUTTONS_PIN, keysDef, 4);


    auto *lcd = new LiquidCrystal(DISPLAY_RS_PIN, DISPLAY_ENABLE_PIN, DISPLAY_D0_PIN, DISPLAY_D1_PIN,
                                  DISPLAY_D2_PIN, DISPLAY_D3_PIN);
    lcd->begin(16, 2);


    values = new Values();
    //values.loadFromEEprom();
    relays = new Relays(HUMIDIFICATION_RELAY_PIN, HEATING_RELAY_PIN);
    thSensors = new THSensors(WET_SENSOR_ADR, DRY_SENSOR_ADR, TEMP_SENSOR_PIN, 5000);
    monitoring = new Monitoring(5 * 1000);
    keys = new Keys(BUTTONS_PIN, analogButton);

    thControl = new THControl(relays, 5000);

    homePage = new HomePage(lcd, values);
    delay(200);
}

void HumidityController::loop(unsigned long currentMillis) {

    thSensors->update(values, millis());
    keys->update(values, millis());
    values->update(millis());
    monitoring->update(values, millis());
    thControl->update(values, millis());
    homePage->render();
}
