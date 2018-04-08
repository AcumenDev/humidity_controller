#ifndef Sensors_h
#define Sensors_h

#include <OneWire.h>
#include <DallasTemperature.h>

#include "Values.hpp"
#include "IntervalWorkerBase.hpp"
#include "PsychrometricAlgorithm.hpp"
#include "PsychrometricAlgorithmStatic.hpp"

class THSensors: public IntervalWorkerBase {

	OneWire *oneWire;
	DallasTemperature *ds;
	const	uint8_t * wetSensorAdr;
	const	uint8_t * drySensorAdr;
	void searchSensors();
public:
	THSensors(const uint8_t * wetSensorAdr,const uint8_t * drySensorAdr, uint8_t pin,
			int interval);
	void work(Values *values, unsigned long currentMillis) override;
};

#endif
