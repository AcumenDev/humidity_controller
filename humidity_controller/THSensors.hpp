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

	DeviceAddress wetSensor = { 0x28, 0xFF, 0x7A, 0xC4, 0xB1, 0x17, 0x4, 0x5B };
	DeviceAddress drySensor = { 0x28, 0xFF, 0x0, 0xC2, 0xB1, 0x17, 0x4, 0x82 };

	void searchSensors();
public:
	THSensors(int interval);
	void work(Values *values, unsigned long currentMillis) override;
};

#endif
