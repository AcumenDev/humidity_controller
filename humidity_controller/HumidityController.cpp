
#include "HumidityController.hpp"


Menu *HumidityController::buildMenu(Values *values, Display *display) {




  auto *tGis = new PageValue("Gisteris", new FloatChanger(&(values->getClimatVal(TEMPERATURE)->gisteris), 0, 10, 0.1));
  auto *tCur = new PageValue("Target", new FloatChanger(&(values->getClimatVal(TEMPERATURE)->target), 1, 30, 0.1));
  PageBase *tPages[] = {tCur, tGis};
  auto *tGroup = new PageGroup("Temperature", tPages, 2);


  auto *hGis = new PageValue("Gisteris", new FloatChanger(&(values->getClimatVal(HUMIDITY)->gisteris), 0, 20, 1));
  auto *hCur = new PageValue("Target", new FloatChanger(&(values->getClimatVal(HUMIDITY)->target), 10, 99, 1));
  PageBase *hPages[] = {hGis, hCur};
  auto *hGroup = new PageGroup("Humidity", hPages, 2);

  PageBase *mainPages[] = {tGroup, hGroup};
  auto *pageGroup = new PageGroup(mainPages, 2);
  return new Menu(display, 2, pageGroup, new HomePage(values));

}


void HumidityController::setup() {
  Serial.begin(9600);


  Key keysDef[] = {Key(1, 100, 200), Key(2, 200, 400), Key(3, 600, 800)};
  analogButton = new AnalogButton(BUTTONS_PIN, keysDef, 3);


  auto *lcd = new LiquidCrystal(DISPLAY_RS_PIN, DISPLAY_ENABLE_PIN, DISPLAY_D0_PIN, DISPLAY_D1_PIN,
                                DISPLAY_D2_PIN, DISPLAY_D3_PIN);
  lcd->begin(16, 2);

  DisplayLiquidCrystal * disp = new DisplayLiquidCrystal(lcd);


  values = new Values();
  //values.loadFromEEprom();
  relays = new Relays(HUMIDIFICATION_RELAY_PIN, HEATING_RELAY_PIN);
  thSensors = new THSensors(WET_SENSOR_ADR, DRY_SENSOR_ADR, TEMP_SENSOR_PIN, 5000);
  monitoring = new Monitoring(5 * 1000);
  keys = new Keys(BUTTONS_PIN, analogButton, menu);

  thControl = new THControl(relays, 5000);

  menu = buildMenu(values, disp);
  delay(200);
}

void HumidityController::loop(unsigned long currentMillis) {
  menu->update(values, millis());
  thSensors->update(values, millis());
  keys->update(values, millis());

  values->update(millis());
  monitoring->update(values, millis());
  thControl->update(values, millis());
}
