#ifndef EEPROM_UTILS_HPP_
#define EEPROM_UTILS_HPP_

#include <EEPROM.h>
#include <stdint.h>

template<class T> uint8_t EEPROM_writeAnything(uint8_t ee, const T& value) {
	const uint8_t* p = (const uint8_t*) (const void*) &value;
	uint8_t i;
	for (i = 0; i < sizeof(value); i++)
		EEPROM.update(ee++, *p++);
	return i;
}

#endif
