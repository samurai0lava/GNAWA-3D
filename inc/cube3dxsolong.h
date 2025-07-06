#ifndef CUBE3DXSOLONG_H
# define CUBE3DXSOLONG_H

# include "../cub3D-42/inc/cube3d.h"
# include "../So_long_42/inc/so_long.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

typedef enum { GAME_SOLONG, GAME_CUB3D } t_game_state;

typedef struct s_master 
{
    t_game_state state;
    void *mlx;
    void *win;
    t_data solong;
    t_cube cube3d;
} t_master;


void init_master(t_master *master);
void free_master(t_master *master);
int main_solong(int argc, char **argv);
int main_cube3d(int argc, char **argv);
int handle_game_switch(t_master *master, int keycode);

#endif