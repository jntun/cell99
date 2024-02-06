cmake_minimum_required(VERSION 3.25)
project(Cell99 C)

set(CMAKE_C_STANDARD 99)

include_directories("${CMAKE_SOURCE_DIR}/include")
include_directories("${CMAKE_SOURCE_DIR}/private")
include_directories("${CMAKE_SOURCE_DIR}/entity/include")    # Entity interface
include_directories("${CMAKE_SOURCE_DIR}/component/include") # Components interface
include_directories("${CMAKE_SOURCE_DIR}/system/include")    # Systems interface

file(GLOB FLECS "/usr/local/opt/flecs/libflecs.dylib")
message("flecs = ${FLECS}")

add_executable(Cell99
        main.c

        private/util.h
        private/game.h game.c

        ## ENTITIES ##
        entity/include/client.h entity/client.c

        ## COMPONENTS ##
        component/include/cell.h component/cell.c
        component/include/pos.h

        ## SYSTEMS ##
)

target_link_libraries(Cell99 ${FLECS})

target_compile_options(Cell99 PUBLIC -O3)
target_compile_options(Cell99 PUBLIC -Wall)
target_compile_options(Cell99 PUBLIC -g)