#include <SDL.h>

#include "util.h"
#include "game.h"

struct engine {
    uint8_t running;

    cell99_game_t game;
};

void input(struct engine *engine)
{
    SDL_Event e;

    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            engine->running = false;
        }
    }
}

int main()
{
    printf("Hello, " KTXT(KRED, "cell99") "!\n");
    struct engine cell99 = {1, init()};

    cell99.game = start(cell99.game);
    do {
        if (cell99.game.running) cell99.game = run(cell99.game);

        input(&cell99);
    } while (cell99.running);

    ecs_time_t stop;
    ecs_os_get_time(&stop);
    ecs_time_t runtime = ecs_time_sub(stop, cell99.game.start);
    printf("ran: %lld ticks\nstart: %d stop: %d total: %d\n", cell99.game.epoch, cell99.game.start.nanosec, stop.nanosec, runtime.nanosec);

EXIT:
    close(cell99.game);

    return 0;
}
