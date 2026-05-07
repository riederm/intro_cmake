cmake_minimum_required(VERSION 3.20)
project(mqtt_demo C)

find_path(MOSQUITTO_INCLUDE_DIR mosquitto.h)
find_library(MOSQUITTO_LIBRARY mosquitto)

if(NOT MOSQUITTO_INCLUDE_DIR OR NOT MOSQUITTO_LIBRARY)
    message(FATAL_ERROR
        "libmosquitto wurde nicht gefunden. Installation:\n"
        "  sudo apt install libmosquitto-dev")
endif()

add_library(mosquitto::mosquitto UNKNOWN IMPORTED)
set_target_properties(mosquitto::mosquitto PROPERTIES
    IMPORTED_LOCATION             "${MOSQUITTO_LIBRARY}"
    INTERFACE_INCLUDE_DIRECTORIES "${MOSQUITTO_INCLUDE_DIR}")

add_executable(mqtt_demo main.c)
target_link_libraries(mqtt_demo PRIVATE mosquitto::mosquitto)
