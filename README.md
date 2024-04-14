cell99
================================
Cellular Automata Engine in C99
--------------------------------

### About 

Cell99 is a unique game/engine for building cellular automata based systems. It is based
on using an Entity-Component-System architecture.
-----------

### Dependencies

This project uses *[Flecs](https://github.com/SanderMertens/flecs)*, so it is required to have flecs.h somewhere cmake can include it

The header **_must_** match the version of the dynamic library (flecs.dylib, flecs.so) that is being linked against.

-------

### Layout 

| Directory | Handles                    |
|-----------|----------------------------|
| client    | input, networking, ui, etc |
| world     | position, cell             | 
| falia     | renderer                   |
------