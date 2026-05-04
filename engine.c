#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "engine.h"
#include "config.h"

int **allocate_enviroment()
{
    int **env = malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++)
    {
        env[i] = calloc(COLS, sizeof(int));
    }
    return env;
}

void free_enviroment(int **env)
{
    for (int i = 0; i < ROWS; i++)
    {
        free(env[i]);
    }
    free(env);
}

void seed_population(int **env)
{
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            env[i][j] = (rand() % 7 == 0) ? 1 : 0;
        }
    }
}

void render_frame(int **env)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (env[i][j] == 0)
            {
                printf("%s", EMPTY);
            }
            else if (env[i][j] == 1)
            {
                printf("%s", MITOSIS);
            }
            else if (env[i][j] == 2)
            {
                printf("%s", APOPTOSIS);
            }
        }
        printf("\n");
    }
}

void clear_console()
{
    printf("\033[H\033[J");
}