cmake_minimum_required(VERSION 3.25)
project(cell99 C)

set(CMAKE_C_STANDARD 99)

include_directories("${CMAKE_SOURCE_DIR}/include")
include_directories("${CMAKE_SOURCE_DIR}/private")
include_directories("${CMAKE_SOURCE_DIR}/entity/include")    # Entity interface
include_directories("${CMAKE_SOURCE_DIR}/component/include") # Components interface
include_directories("${CMAKE_SOURCE_DIR}/render/")

# FLECS #
file(GLOB FLECS "/usr/local/opt/flecs/libflecs.dylib")
message("flecs = ${FLECS}")

# SDL2 #
include_directories("/usr/local/opt/sdl2/include/SDL2")
file(GLOB sdl2 "/usr/local/opt/sdl2/lib/libSDL2.dylib")

add_executable(cell99
        main.c

        private/util.h
        private/game.h game.c

        render/render.h render/render.c

        ## ENTITIES ##
        entity/include/client.h entity/client.c

        ## COMPONENTS ##
        component/include/component.h
        component/include/cell.h component/cell.c
        component/include/pos.h
)

target_link_libraries(cell99 ${FLECS})
target_link_libraries(cell99 ${sdl2})

target_compile_options(cell99 PUBLIC -O3)
target_compile_options(cell99 PUBLIC -Wall)
target_compile_options(cell99 PUBLIC -g)
