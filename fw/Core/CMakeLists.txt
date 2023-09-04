cmake_minimum_required(VERSION 3.16)

target_sources(sBMS.elf PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/adc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/app_freertos.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/fdcan.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/gpio.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/i2c.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/rtc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/spi.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/stm32g0xx_hal_msp.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/stm32g0xx_hal_timebase_tim.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/stm32g0xx_it.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/system_stm32g0xx.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/tim.c
)

target_include_directories(sBMS.elf PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Inc/
)
