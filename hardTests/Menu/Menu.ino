
#include <LiquidCrystal.h>
#include "Keys.hpp"
#include "Config.hpp"
#include "Monitoring.hpp"

#include "Menu.hpp"
#include "PageGroup.hpp"
#include "PageValue.hpp"
#include "FloatChanger.hpp"
#include "HomePage.hpp"


Values *values;
Keys *keys;
Menu<LiquidCrystal> *menu;
AnalogButton *analogButton;
Monitoring *monitoring;

Menu<LiquidCrystal> * buildMenu(Values *values, LiquidCrystal *display) {

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


void setup() {
    Serial.begin(9600);

    Key keysDef[] = {Key(1, 100, 200), Key(2, 200, 400), Key(3, 600, 800)};
    analogButton = new AnalogButton(BUTTONS_PIN, keysDef, 3);


    LiquidCrystal *lcd = new LiquidCrystal(DISPLAY_RS_PIN, DISPLAY_ENABLE_PIN, DISPLAY_D0_PIN, DISPLAY_D1_PIN,
                                           DISPLAY_D2_PIN, DISPLAY_D3_PIN);
    lcd->begin(16, 2);


    values = new Values();
    keys = new Keys(BUTTONS_PIN, analogButton, menu);
    monitoring = new Monitoring(5 * 1000);
    menu = buildMenu(values, lcd);
    delay(200);
}

void loop() {
    menu->update(values, millis());

    keys->update(values, millis());
    //display->update(values, millis());
    values->update(millis());
    monitoring->update(values, millis());

}