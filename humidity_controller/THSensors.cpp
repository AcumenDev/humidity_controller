#include "THSensors.hpp"

THSensors::THSensors(uint8_t * wetSensorAdr, uint8_t * drySensorAdr,
		uint8_t pin, int interval) :
		IntervalWorkerBase(interval) {

	this->wetSensorAdr = wetSensorAdr;
	this->drySensorAdr = drySensorAdr;
	oneWire = new OneWire(pin);
	ds = new DallasTemperature(oneWire);
	ds->begin();
	searchSensors();
}

void THSensors::work(Values *values, unsigned long currentMillis) {
	ds->requestTemperatures();
	values->getClimatVal(TEMPERATURE)->setCurrent(ds->getTempC(drySensorAdr));
	values->wetT = ds->getTempC(wetSensorAdr);
	/*DEBUG_PRINT("-");
	Serial.println(ds->getTempC(wetSensorAdr));
	Serial.println(ds->getTempC(drySensorAdr));*/

	values->getClimatVal(HUMIDITY)->setCurrent(PsychrometricAlgorithm::computeHumidity(values->getClimatVal(TEMPERATURE)->getCurrent(), values->wetT));
}

void THSensors::searchSensors() {
	byte addr[8];
	Serial.println();
	int number = 0;
	while (oneWire->search(addr)) {
		Serial.print(++number);
		Serial.print(" : ");
		for (int i = 0; i < 8; i++) {
			Serial.print(' ');
			Serial.print(addr[i], HEX);
		}
		Serial.println();
	}

	if (number == 0) {
		Serial.println("Sensors not found!");
	}

}
