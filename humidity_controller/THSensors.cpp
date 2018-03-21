#include "THSensors.hpp"

THSensors::THSensors(int interval) :
		IntervalWorkerBase(interval) {
	oneWire = new OneWire(A1); // вход датчиков 18b20 (a 4.7K resistor is necessary)
	ds = new DallasTemperature(oneWire);
	ds->begin();
	searchSensors();
}

void THSensors::work(Values *values, unsigned long currentMillis) {
	values->temperature.value = ds->getTempC(drySensor);
	values->wetT = ds->getTempC(wetSensor);

	values->humidity.value = PsychrometricAlgorithm::computeHumidity(values->temperature.value,
			values->wetT);
//	values->humStat = PsychrometricAlgorithmStatic::computeHumidity(
//			values->dryT, values->wetT);

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
