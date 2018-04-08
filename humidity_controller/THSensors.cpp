#include "THSensors.hpp"
#include "DebugUtils.hpp"

THSensors::THSensors(const uint8_t * wetSensorAdr, const uint8_t * drySensorAdr,
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
	DEBUG_PRINTLN("")
	int number = 0;
	while (oneWire->search(addr)) {
		++number;
		DEBUG_PRINT((int)number);
		DEBUG_PRINT(" : ")
		for (int i = 0; i < 8; i++) {
			Serial.print(' ');
			DEBUG_PRINT(' ')
			DEBUG_PRINT(addr[i], HEX)
		}
		DEBUG_PRINTLN("")
	}

	if (number == 0) {
		DEBUG_PRINTLN("Sensors not found!")
	}

}
