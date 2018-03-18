################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/vst/Arduino/libraries/Adafruit_BME280_Library/Adafruit_BME280.cpp 

LINK_OBJ += \
./libraries/Adafruit_BME280_Library/Adafruit_BME280.cpp.o 

CPP_DEPS += \
./libraries/Adafruit_BME280_Library/Adafruit_BME280.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/Adafruit_BME280_Library/Adafruit_BME280.cpp.o: /home/vst/Arduino/libraries/Adafruit_BME280_Library/Adafruit_BME280.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/vst/soft/eclipse_oxygen/cpp-oxygen/eclipse//arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/vst/soft/eclipse_oxygen/cpp-oxygen/eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.21/cores/arduino" -I"/home/vst/soft/eclipse_oxygen/cpp-oxygen/eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.21/variants/standard" -I"/home/vst/Arduino/libraries/DallasTemperature" -I"/home/vst/Arduino/libraries/LiquidCrystal" -I"/home/vst/Arduino/libraries/LiquidCrystal/src" -I"/home/vst/Arduino/libraries/OneWire" -I"/home/vst/Arduino/libraries/Adafruit_BME280_Library" -I"/home/vst/Arduino/libraries/DHT_sensor_library" -I"/home/vst/soft/eclipse_oxygen/cpp-oxygen/eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM" -I"/home/vst/soft/eclipse_oxygen/cpp-oxygen/eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.21/libraries/EEPROM/src" -I"/home/vst/Arduino/libraries/LedControl" -I"/home/vst/Arduino/libraries/LedControl/src" -I"/home/vst/Arduino/libraries/Adafruit_Unified_Sensor" -I"/home/vst/soft/eclipse_oxygen/cpp-oxygen/eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.21/libraries/SPI" -I"/home/vst/soft/eclipse_oxygen/cpp-oxygen/eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.21/libraries/SPI/src" -I"/home/vst/soft/eclipse_oxygen/cpp-oxygen/eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.21/libraries/Wire" -I"/home/vst/soft/eclipse_oxygen/cpp-oxygen/eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.6.21/libraries/Wire/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


