cmake_minimum_required(VERSION 3.16)
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)
 
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)
set(CMAKE_AR arm-none-eabi-ar)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)
set(CMAKE_OBJDUMP arm-none-eabi-objdump)
set(SIZE arm-none-eabi-size)
# set(CMAKE_CXX_CLANG_TIDY "clang-tidy")
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
set(CMAKE_ASM_FLAGS "${CFLAGS} -x assembler-with-cpp")
set(CMAKE_CXX_FLAGS "-Wno-volatile")
 
project(sBMS LANGUAGES C CXX ASM VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 11)

set(CPU cortex-m0plus)
set(MCU STM32G0B1xx)

if ("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
    message(STATUS "Maximum optimization for speed")
    add_compile_options(-Ofast)
elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "RelWithDebInfo")
    message(STATUS "Maximum optimization for speed, debug info included")
    add_compile_options(-Ofast -g)
elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "MinSizeRel")
    message(STATUS "Maximum optimization for size")
    add_compile_options(-Os)
else ()
    message(STATUS "Minimal optimization, debug info included")
    add_compile_options(-O0 -g)
endif ()

set(LINKER_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/STM32G0B1KCUx_FLASH.ld)

add_link_options(-Wl,-gc-sections,--print-memory-usage,-Map=${PROJECT_BINARY_DIR}/sBMS.map)
add_link_options(-specs=nosys.specs -lstdc++ -mcpu=${CPU} -mthumb -mthumb-interwork -T ${LINKER_SCRIPT})

add_compile_options(-mcpu=${CPU} -mthumb -mthumb-interwork -ffunction-sections -fdata-sections -fno-common -fmessage-length=0)
add_compile_definitions(USE_HAL_DRIVER ${MCU} USE_FULL_LL_DRIVER)

string(TIMESTAMP BUILD_TIMESTAMP_UNIX "+%s")
string(TIMESTAMP BUILD_TIMESTAMP "%d-%m-%Y")

# Settings that cannot be changed from CAN
option(CAN_BUS "Enables the CAN bus. If disabled, the FDCAN peripheral is fully disabled on startup." ON)
option(CHARGE_FET "Ability to close the charge control MOSFETs to shut down charging, if something goes wrong." ON)
option(TEMP_MONITOR "Temperature monitoring using HDC302x IC.s" ON)
option(HUMID_MONITOR "Humidity monitoring using HDC302x ICs." ON)
option(BATTERY_HEALTH_MEASURE "Measure battery health as in the amount of capacity left from the start." ON)
option(CELL_MALFUNCTION_DETECTION "If a cell doesn't behave normally, malfunction detection will throw a critical error about it." ON)

option(CELL_BALANCING "Cell-to-cell balancing with ETA3000 ICs." ON)
option(CELL_SERIES "Amount of cells placed in series." 16)
option(CELL_PARALLEL "Amount of cells placed in parallel." 1)
option(CELL_MAH "mAh of the cell used." 4900)
option(CELL_TYPE "Cell type. Supported: Li-ion, LiPo" Li-ion)

# Settings that can be changed from CAN and are just defaults here
option(CONTROLLED_SELF_DISCHARGE "Controlled self-discharge to go down to nominal storage voltages when required" ON)
option(AUTOSTORAGE "If some time passes (AUTOSTORAGE_TIME) and the 
    battery is on standby, sBMS will automatically start putting the battery into storage mode by discharging it to nominal voltage." ON)
option(AUTOSTORAGE_TIME "Refer to AUTOSTORAGE for more info. In weeks." 4)

option(DISCHARGE_CURRENT_WARNING "Discharge current warning" ON)
option(DISCHARGE_CURRENT_WARNING_THRESHOLD "Amount of discharge current that triggers a warning. In amps." 2)
option(DISCHARGE_CURRENT_ALERT_THRESHOLD "Amount of discharge current that triggers an alert. In amps." 4)

option(DISCHARGE_CURRENT_WARNING "Charge current warning" ON)
option(CHARGE_CURRENT_WARNING_THRESHOLD "Amount of charging current that triggers a warning. In amps." 15)
option(CHARGE_CURRENT_ALERT_THRESHOLD "Amount of charging current that triggers an alert and shuts it off, if CHARGE_FET is enabled. In amps." 20)
option(CHARGER_VOLTAGE_DEVIATION_THRESHOLD "Amount of voltage from the charger that will be considered a big enough deviation from pack voltage that
    it will be deemed unsafe and will shut off charging if CHARGE_FET is enabled. In voltage tenths.
    (if you want to set 0.5V of deviation, you put 5, if 1V, then 10, etc)" 15)

option(TEMP_WARNING_UPPER_THRESHOLD "Upper temperature value that triggers a warning. In Celcius." 40)
option(TEMP_ALERT_UPPER_THRESHOLD "Upper temperature value that triggers an alert, and in case of charging and enabled CHARGE_FET, shuts off charging. In Celcius." 60)
option(TEMP_WARNING_LOWER_THRESHOLD "Lower temperature value that triggers a warning. In Celcius." 15)
option(TEMP_ALERT_LOWER_THRESHOLD "Lower temperature value that triggers an alert, and in case of charging and enabled CHARGE_FET, shuts off charging. In Celcius." 0)
option(TEMP_LOAD_RECOVERY_THRESHOLD "Temperature that cells are required to reach to restart the charging process
    after it was shut off because of high/low temp (see TEMP_ALERT_(UPPER/LOWER)THRESHOLD), or for the controller to
    know if it can enable the load load again. In Celcius." 40)

add_compile_definitions(
    VERSION_MAJOR=${CMAKE_PROJECT_VERSION_MAJOR}
    VERSION_MINOR=${CMAKE_PROJECT_VERSION_MINOR}
    VERSION_PATCH=${CMAKE_PROJECT_VERSION_PATCH}
    BUILD_TIMESTAMP=${BUILD_TIMESTAMP_UNIX})

set(HEX_FILE ${PROJECT_BINARY_DIR}/sBMS.hex)
set(BIN_FILE ${PROJECT_BINARY_DIR}/sBMS.bin)

add_executable(sBMS.elf ${LINKER_SCRIPT})

target_sources(sBMS.elf PUBLIC startup_stm32g0b1xx.s)

add_subdirectory(Core)
add_subdirectory(Drivers)
add_subdirectory(Lib)
add_subdirectory(Middlewares)

set_target_properties(sBMS.elf PROPERTIES LINKER_LANGUAGE CXX)

add_custom_command(TARGET sBMS.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -Oihex $<TARGET_FILE:sBMS.elf> ${HEX_FILE}
        COMMAND ${CMAKE_OBJCOPY} -Obinary $<TARGET_FILE:sBMS.elf> ${BIN_FILE}
        COMMENT "Building ${HEX_FILE}
Building ${BIN_FILE}")