cmake_minimum_required(VERSION 3.25)
project(cell99 C)

set(CMAKE_C_STANDARD 99)

include_directories("${CMAKE_SOURCE_DIR}/include")

# FLECS #
include_directories("${CMAKE_SOURCE_DIR}/flecs/")
file(GLOB FLECS "/usr/local/opt/flecs/libflecs.dylib")
message("flecs = ${FLECS}")

# SDL2 #
include_directories("/usr/local/opt/sdl2/include/SDL2")
file(GLOB sdl2 "/usr/local/opt/sdl2/lib/libSDL2.dylib")
message("sdl2 = ${sdl2}")

add_executable(cell99
        main.c

        world/cell.c
        client/client.c
)

target_link_libraries(cell99 ${FLECS})
target_link_libraries(cell99 ${sdl2})

target_compile_options(cell99 PUBLIC -O3)
target_compile_options(cell99 PUBLIC -Wall)
target_compile_options(cell99 PUBLIC -g)
