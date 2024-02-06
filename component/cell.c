//
// Created by Justin Tunheim on 2/3/24.
//

#include "cell.h"

void cell_build_world(ecs_world_t *ecs)
{
    ECS_COMPONENT(ecs, cell_t);
    ECS_COMPONENT(ecs, pos_t);

    for (uint32_t i=0; i <= CELL_COUNT; i++) {
        ecs_entity_t cell = ecs_new_id(ecs);

        ecs_add(ecs, cell, cell_t);
        ecs_add(ecs, cell, pos_t);

        cell_t type = CELL_TYPE_DEFAULT;
        if (i == CELL_COUNT / 2)
        type = CELL_TYPE_SPAWN;

        ecs_set(ecs, cell, pos_t, {.x = i - (i / CELL_Y) * 10, .y = (i / CELL_Y)});
        ecs_set(ecs, cell, cell_t, { type });
    }

    #ifdef CELL_DBG
    ecs_query_t *q = ecs_query(ecs, {
            .filter.terms = {
                    { .id = ecs_id(pos_t), .inout = EcsIn}
            }
        });

        ecs_iter_t it = ecs_query_iter(ecs, q);

        while (ecs_query_next(&it)) {
            pos_t const *pos = ecs_field(&it, pos_t, 1);

            for (int i=0; i < it.count; i++) {
                printf("[!] match: %d, %d\n", pos[i].x, pos[i].y);
            }
        }
    #endif
}
