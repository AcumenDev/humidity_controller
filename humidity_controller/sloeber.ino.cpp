#ifdef __IN_ECLIPSE__
//This is a automatic generated file
//Please do not modify this file
//If you touch this file your change will be overwritten during the next build
//This file has been generated on 2018-03-31 17:21:23

#include "Arduino.h"
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

Menu<LiquidCrystal> * buildMenu(Values *values, LiquidCrystal *display) ;
void setup() ;
void loop() ;

#include "humidity_controller.ino"


#endif
