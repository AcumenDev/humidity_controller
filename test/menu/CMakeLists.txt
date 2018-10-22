cmake_minimum_required(VERSION 3.2)
project(test_humidity_controller)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11  -fpermissive")

#add_definitions(-DDEBUG -DCLIMATE_DEBUG)
#include_directories(BEFORE ../humidity_controller)
include_directories(BEFORE stub)


set(HEADER_FILES
        src/FloatChanger.hpp
        src/HomePage.hpp
        src/Changer.hpp
        src/Menu.hpp
        src/PageBase.hpp
        src/PageGroup.hpp
        src/PageValue.hpp
        src/Config.hpp
        src/Display.hpp)


set(SOURCE_FILES
        TestMenu.cpp
        src/FloatChanger.cpp
        stub/Arduino.cpp
        stub/LedControl.cpp
        stub/HardwareSerial.cpp stub/DisplayStub.hpp)

add_executable(humidity_controller ${SOURCE_FILES} ${SOURCE_FILES_CLIMATE}) #[[ ]]


