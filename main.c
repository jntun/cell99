#include <stdlib.h>
#include <flecs.h>

#include "util.h"
#include "game.h"

int main() {
    printf("Hello, " KTXT(KRED, "cell99") "!\n");

    struct cell99 game = init();
    for (game = start(game); game.running; game = run(game)) {};

    ecs_time_t stop;
    ecs_os_get_time(&stop);
    ecs_time_t runtime = ecs_time_sub(stop, game.start);
    printf("ran: %lld ticks\nstart: %d stop: %d total: %d\n", game.epoch, game.start.nanosec, stop.nanosec, runtime.nanosec);

EXIT:
    close(game);
    return 0;
}
