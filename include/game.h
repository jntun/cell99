//
// Created by Justin Tunheim on 2/3/24.
//

#ifndef CELL99_GAME_H
#define CELL99_GAME_H

#include <stdlib.h>
#include <flecs.h>

#include "world.h"
#include "client.h"
#include "util.h"

static uint32_t const MAX_CLIENTS = 100 - 1;
static uint64_t const EPOCHS      = 1000 - 1;

struct init_flags {
    unsigned int cold  : 1;
    unsigned int pause : 1;
    unsigned int epoch : 1;
};

/*!
 * @struct
 * The global scope of an engine's execution of a game's main loop
 */
typedef struct cell99_game_t {
    uint8_t running;
    uint64_t   epoch;
    ecs_time_t start;
    struct init_flags init;

    cell99_passenger_t passenger;
    ecs_world_t *ecs;
} cell99_game_t;

static struct cell99_game_t init()
{
    struct cell99_game_t const game = {
            .running = false,
            .epoch   = 0,
            .init    = {
                .cold = 1,
                .pause = 0,
                .epoch = true,
            },

            .ecs     = ecs_init(),
    };

    return game;
}

static struct cell99_game_t run(struct cell99_game_t game)
{
    if (game.init.cold) {
        game.init.cold = 0;
    }

    ecs_time_t start;
    ecs_os_get_time(&start);

    if (game.init.epoch && game.epoch == EPOCHS)
        game.running = false;

    game.epoch++;

    ecs_time_t stop;
    ecs_os_get_time(&stop);
    ecs_time_t delta = ecs_time_sub(stop, start);

    return game;
}

static struct cell99_game_t start(struct cell99_game_t game)
{
    cell_build_world(game.ecs);
    game.passenger = cell99_passenger(game.ecs);
    game.running = 1;
    ecs_os_get_time(&game.start);

    return game;
}

static void close(struct cell99_game_t game)
{
    ecs_fini(game.ecs);
}

#endif //CELL99_GAME_H
