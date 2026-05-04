#include "biology.h"
#include "config.h"

int count_living_cells(int **env, int r, int c)
{
    int count = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }
            int nr = (r + i + ROWS) % ROWS;
            int nc = (c + j + COLS) % COLS;

            if (env[nr][nc] == 1 || env[nr][nc] == 2)
            {
                count++;
            }
        }
    }
    return count;
}

void process_life_cycle(int **current_env, int **next_env)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            int living_neighbors = count_living_cells(current_env, i, j);
            int state = current_env[i][j];

            if (state == 1 || state == 2)
            {
                if (living_neighbors == 2 || living_neighbors == 3)
                {
                    next_env[i][j] = 2;
                }
                else
                {
                    next_env[i][j] = 3;
                }
            }
            else
            {
                if (living_neighbors == 3)
                {
                    next_env[i][j] = 1;
                }
                else
                {
                    next_env[i][j] = 0;
                }
            }
        }
    }
}