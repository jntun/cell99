//
// Created by Justin Tunheim on 2/3/24.
//

#ifndef CELL99_GAME_H
#define CELL99_GAME_H

#include <stdlib.h>
#include <flecs.h>

#include "util.h"
#include "cell.h"
#include "client.h"

static uint32_t const MAX_CLIENTS = 100 - 1;
static uint64_t const EPOCHS      = 100 - 1;

struct init_flags {
    unsigned int cold  : 1;
    unsigned int pause : 1;
};

/*!
 * @struct
 * Highest level state of the currently executing binary
 */
struct cell99 {
    bool       running;
    uint64_t   epoch;
    ecs_time_t start;
    struct init_flags init;

    cell99_passenger_t passenger;
    ecs_world_t *ecs;
};

static struct cell99 init()
{
    struct cell99 game = {
            .running = false,
            .epoch   = 0,
            .init    = {.cold = 1, .pause = 0},

            .ecs     = ecs_init(),
    };
    ecs_os_get_time(&game.start);

    return game;
}

static struct cell99 run(struct cell99 game)
{
    if (game.init.cold) {
        game.init.cold = 0;
    }

    ecs_time_t start;
    ecs_os_get_time(&start);
    if (game.epoch == EPOCHS)
        game.running = false;

    game.epoch++;

    ecs_time_t stop;
    ecs_os_get_time(&stop);
    ecs_time_t delta = ecs_time_sub(stop, start);

    return game;
}

static struct cell99 start(struct cell99 game)
{
    cell_build_world(game.ecs);
    game.passenger = cell99_passenger(game.ecs);
    game.running = true;
    return game;
}

static void close(struct cell99 game)
{
    ecs_fini(game.ecs);
}

#endif //CELL99_GAME_H
