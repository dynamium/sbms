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