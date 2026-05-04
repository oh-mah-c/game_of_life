#include <stdio.h>
#include <unistd.h>
#include "engine.h"
#include "biology.h"
#include "config.h"

int main()
{
    int **current_env = allocate_enviroment();
    int **next_env = allocate_enviroment();
    int **temp;

    clear_console();
    seed_population(current_env);

    while (1)
    {
        clear_console();
        render_frame(current_env);
        process_life_cycle(current_env, next_env);

        temp = current_env;
        current_env = next_env;
        next_env = temp;

        usleep(TICK_RATE_MS * 1000);
    }

    free_enviroment(current_env);
    free_enviroment(next_env);
    return 0;
}