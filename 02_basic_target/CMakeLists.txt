cmake_minimum_required(VERSION 3.20)
project(firmware C)

add_executable(firmware
    main.c
    uart.c
    led.c
)

target_compile_options(firmware PRIVATE -Wall -O2)

