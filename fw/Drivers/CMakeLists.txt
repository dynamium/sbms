cmake_minimum_required(VERSION 3.16)

target_sources(sBMS.elf PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_adc.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_dma.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_rcc.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_rcc.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_rcc_ex.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_flash.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_flash_ex.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_gpio.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_dma.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_dma_ex.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_pwr.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_pwr_ex.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_cortex.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_exti.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_fdcan.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_tim.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_tim_ex.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_adc.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_adc_ex.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_i2c.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_i2c_ex.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_rtc.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_rtc_ex.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_spi.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_spi_ex.c
)

target_include_directories(sBMS.elf PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G0xx_HAL_Driver/Inc
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G0xx_HAL_Driver/Inc/Legacy
    ${CMAKE_CURRENT_SOURCE_DIR}/CMSIS/Device/ST/STM32G0xx/Include
    ${CMAKE_CURRENT_SOURCE_DIR}/CMSIS/Include
)