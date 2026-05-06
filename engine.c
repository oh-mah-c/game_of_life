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
    char buffer[ROWS * COLS * 30 + ROWS + 1];
    int pos = 0;

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            const char *symbol = EMPTY;
            if (env[i][j] == 1)
            {
                symbol = MITOSIS;
            }
            else if (env[i][j] == 2)
            {
                symbol = MATURE;
            }
            else if (env[i][j] == 3)
            {
                symbol = APOPTOSIS;
            }
            else if (env[i][j] == 4)
            {
                symbol = FADE1;
            }
            else if (env[i][j] == 5)
            {
                symbol = FADE2;
            }
            else if (env[i][j] == 6)
            {
                symbol = FADE3;
            }

            int len = sprintf(&buffer[pos], "%s", symbol);
            pos += len;
        }
        buffer[pos++] = '\n';
    }
    buffer[pos] = '\0';

    fputs(buffer, stdout);
    fflush(stdout);
}

void clear_console()
{
    static int first_run = 1;
    if (first_run)
    {
        printf("\033[?25l\033[H\033[J");
        first_run = 0;
    }
    else
    {
        printf("\033[H");
    }

    fflush(stdout);
}