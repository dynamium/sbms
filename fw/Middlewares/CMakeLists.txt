cmake_minimum_required(VERSION 3.16)

target_sources(sBMS.elf PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Third_Party/FreeRTOS/Source/croutine.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/Third_Party/FreeRTOS/Source/event_groups.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/Third_Party/FreeRTOS/Source/list.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/Third_Party/FreeRTOS/Source/queue.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/Third_Party/FreeRTOS/Source/stream_buffer.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/Third_Party/FreeRTOS/Source/tasks.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/Third_Party/FreeRTOS/Source/timers.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/cmsis_os2.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/Third_Party/FreeRTOS/Source/portable/MemMang/heap_4.c 
    ${CMAKE_CURRENT_SOURCE_DIR}/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0/port.c
)

target_include_directories(sBMS.elf PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Third_Party/FreeRTOS/Source/include 
    ${CMAKE_CURRENT_SOURCE_DIR}/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 
    ${CMAKE_CURRENT_SOURCE_DIR}/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 
)