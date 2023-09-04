cmake_minimum_required(VERSION 3.16)

set(LIBCANARD_SRC ${CMAKE_CURRENT_SOURCE_DIR}/libcanard/libcanard)
set(UWLKV_SRC ${CMAKE_CURRENT_SOURCE_DIR}/uWLKV/src)

target_sources(sBMS.elf PUBLIC
    ${LIBCANARD_SRC}/canard.c
    ${UWLKV_SRC}/entry.c
    ${UWLKV_SRC}/map.c
    ${UWLKV_SRC}/storage.c
    ${UWLKV_SRC}/uwlkv.c
)

target_include_directories(sBMS.elf PUBLIC
    ${LIBCANARD_SRC}
    ${UWLKV_SRC}/include
)