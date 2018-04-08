#ifndef Config_HPP_
#define Config_HPP_

#define CLIMATE_DEBUG



///Номер порта, адреса датчиков температуры
#define TEMP_SENSOR_PIN A1
///мокрый датчик температуры
const uint8_t WET_SENSOR_ADR[8] = { 0x28, 0xFF, 0x7A, 0xC4, 0xB1, 0x17, 0x4, 0x5B };
///сухой датчик температуры
const uint8_t DRY_SENSOR_ADR[8] = { 0x28, 0xFF, 0x0, 0xC2, 0xB1, 0x17, 0x4, 0x82 };
///

///Номера портов куда подключен дисплей
#define DISPLAY_RS_PIN 8
#define DISPLAY_ENABLE_PIN 9
#define DISPLAY_D0_PIN 4
#define DISPLAY_D1_PIN 5
#define DISPLAY_D2_PIN 6
#define DISPLAY_D3_PIN 7
///


///Номера порта куда подлюченны кнопки
#define BUTTONS_PIN A0

///


///Номера портов куда подключенны реле
#define HUMIDIFICATION_RELAY_PIN A2
#define HEATING_RELAY_PIN A3
///


///Настройка управление влажностью
#define HUMIDITY_TARGET 85
#define HUMIDITY_GISTERIS 2

#define MIN_TARGET_HUMIDITY 20
#define MAX_TARGET_HUMIDITY 99
////

///Настройка управление влажностью
#define TEMPERATURE_TARGET 28
#define TEMPERATURE_GISTERIS 1


#define MIN_TARGET_TEMPERATURE 10
#define MAX_TARGET_TEMPERATURE 90
/////


///Адреса  EEPROM для сохранения настроек, чтобы не терять при выключении
///#define TARGET_HUMIDITY_EEPROM_ADR 1



#endif
