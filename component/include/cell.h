//
// Created by Justin Tunheim on 2/3/24.
//

#ifndef CELL99_CELL_H
#define CELL99_CELL_H

#include "flecs.h"

#include "pos.h"

#define CELL_X 10
#define CELL_Y 10

static uint32_t const CELL_COUNT  = (CELL_X * CELL_Y) - 1;
#define CELL_TYPE_MAX (100 - 1)

typedef enum cell_t {
    CELL_TYPE_DEFAULT = 0,
    CELL_TYPE_SPAWN,

    CELL_TYPE_MAXIMUM = CELL_TYPE_MAX
} cell_t;

void cell_build_world(ecs_world_t *ecs);

#endif //CELL99_CELL_H
