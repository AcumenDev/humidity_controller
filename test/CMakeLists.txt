cmake_minimum_required(VERSION 3.2)
project(test_humidity_controller)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lstdc++ -fpermissive")

#add_definitions(-DDEBUG -DCLIMATE_DEBUG)
include_directories(BEFORE stub)

set(HEADER_FILES_CLIMATE
        stub/EEPROM.h
        stub/Arduino.h
        stub/DHT.h
        stub/LedControl.h
        stub/SoftwareSerial.h
        stub/HardwareSerial.hpp
        ../humidity_controller/ServoMotors.hpp

        ../humidity_controller/Button.hpp
        ../humidity_controller/Keys.hpp
        ../humidity_controller/Relays.hpp
        ../humidity_controller/Config.hpp
        ../humidity_controller/IntervalWorkerBase.hpp
        ../humidity_controller/Value.hpp
        ../humidity_controller/TimeUtils.hpp
        ../humidity_controller/Monitoring.hpp
        ../humidity_controller/DebugUtils.hpp
        ../humidity_controller/Menu.hpp)

set(SOURCE_FILES_CLIMATE
        stub/EEPROM.cpp
        stub/Arduino.cpp
        stub/DHT.cpp
        stub/LedControl.cpp
        stub/HardwareSerial.cpp
        ../humidity_controller/AnalogButton.cpp
        ../humidity_controller/AnalogButton.hpp
        ../humidity_controller/Keys.cpp
        ../humidity_controller/Relays.cpp
        ../humidity_controller/IntervalWorkerBase.cpp
        ../humidity_controller/Monitoring.cpp
        ../humidity_controller/HumidityControl.cpp
        ../humidity_controller/HumidityControl.hpp
        ../humidity_controller/PageBase.hpp
        ../humidity_controller/PageGroup.hpp
        ../humidity_controller/PageValue.hpp
        ../humidity_controller/Changer.cpp
        ../humidity_controller/Changer.hpp
        ../humidity_controller/FloatChanger.cpp
        ../humidity_controller/FloatChanger.hpp)

set(SOURCE_FILES testAnalogButton.cpp stub/LiquidCrystal.h)
add_executable(humidity_controller ${SOURCE_FILES} ${SOURCE_FILES_CLIMATE})