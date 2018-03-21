#include "Monitoring.hpp"

Monitoring::Monitoring(int interval) :
		IntervalWorkerBase(interval) {
}

void Monitoring::work(Values *values, unsigned long currentMillis) {
	Serial.print(currentMillis / 1000);
	Serial.print("Temperature Mokry: ");
	Serial.print(values->wetT);
	Serial.println(" *C");
	Serial.print("Temperature Syhoi: ");
	Serial.print(values->temperature.value);
	Serial.println(" *C");
	Serial.print("Humidity dyn:  ");
	Serial.print(values->humidity.value);
	Serial.println("%    ");

	/*Serial.print("Humidity stat:  ");
	Serial.print(values->humStat);
	Serial.println("%    ");
*/
#ifdef CLIMATE_DEBUG_RAM
	Serial.print("\t");
	Serial.print(DebugUtils::getfreeRam());
#endif
	Serial.print("\n");
	Serial.flush();
}

