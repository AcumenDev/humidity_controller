#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>
#include "PsychrometricAlgorithm.hpp"
#include "PsychrometricAlgorithmStatic.hpp"

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
OneWire oneWire(A1); // вход датчиков 18b20 (a 4.7K resistor is necessary)
DallasTemperature ds(&oneWire);

DeviceAddress sensor1 = {0x28, 0xFF, 0x7A, 0xC4, 0xB1, 0x17, 0x4, 0x5B};
DeviceAddress sensor2 = {0x28, 0xFF, 0x0, 0xC2, 0xB1, 0x17, 0x4, 0x82};



void setup() {
  ds.begin();
  lcd.begin(16, 2);
  Serial.begin(9600);
  searchSensors();
}

void searchSensors() {
  byte addr[8];
  Serial.println();
  int number = 0;
  while (oneWire.search(addr)) {
    Serial.print(++number);
    Serial.print(" : ");
    for (int  i = 0; i < 8; i++) {
      Serial.print(' ');
      Serial.print(addr[i], HEX);
    }
    Serial.println();
  }

  if ( number == 0) {
    Serial.println("Sensors not found!");
  }

}

void loop() {

  ds.requestTemperatures(); // считываем температуру с датчиков

  float dryT = ds.getTempC(sensor2);
  float wetT = ds.getTempC(sensor1);

  lcd.setCursor(0, 0);
  lcd.print(" Temp: ");
  lcd.print(dryT);
  lcd.println(" C   ");
  Serial.print("Temperature Mokry: ");
  Serial.print(wetT);
  Serial.println(" *C");
  Serial.print("Temperature Syhoi: ");
  Serial.print(dryT);
  Serial.println(" *C");


  float humDyn = PsychrometricAlgorithm::computeHumidity(dryT, wetT);
  float humStat = PsychrometricAlgorithmStatic::computeHumidity(dryT, wetT);

  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humDyn);
  lcd.println(" %    ");
  Serial.print("Humidity dyn:  ");
  Serial.print(humDyn);
  Serial.println("%    ");

  Serial.print("Humidity stat:  ");
  Serial.print(humStat);
  Serial.println("%    ");
  delay(5000);
}
