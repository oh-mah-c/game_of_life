#ifndef ENGINE_H
#define ENGINE_H

int **allocate_enviroment();
void free_enviroment(int **env);
void seed_population(int **env);
void render_frame(int **env);
void clear_console();

#endif