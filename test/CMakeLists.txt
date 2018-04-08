cmake_minimum_required(VERSION 3.2)
project(test_humidity_controller)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lstdc++ -fpermissive")

#add_definitions(-DDEBUG -DCLIMATE_DEBUG)
#include_directories(BEFORE ../humidity_controller)
include_directories(BEFORE stub)


set(SOURCE_FILES_CLIMATE
        stub/EEPROM.cpp
        stub/Arduino.cpp
        stub/DHT.cpp
        stub/LedControl.cpp
        stub/HardwareSerial.cpp
        ../humidity_controller/AnalogButton.cpp
        ../humidity_controller/Keys.cpp
        ../humidity_controller/Relays.cpp
        ../humidity_controller/THSensors.cpp
        ../humidity_controller/IntervalWorkerBase.cpp
        ../humidity_controller/Monitoring.cpp
        ../humidity_controller/THControl.cpp
        ../humidity_controller/FloatChanger.cpp)


set(SOURCE_FILES testAnalogButton.cpp ../humidity_controller/HumidityController.cpp ../humidity_controller/HumidityController.hpp stub/OneWire.h stub/DallasTemperature.h ../hardTests/AnalogButton/UtilsButton.hpp)
add_executable(humidity_controller ${SOURCE_FILES} ${SOURCE_FILES_CLIMATE} ) #[[ ]]


