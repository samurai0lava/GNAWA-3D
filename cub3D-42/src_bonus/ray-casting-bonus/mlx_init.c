/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samurai0lava <samurai0lava@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:44:52 by iouhssei          #+#    #+#             */
/*   Updated: 2025/07/07 13:59:28 by samurai0lav      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

int	get_texture_pixel(t_data *texture, int x, int y)
{
	char	*pixel;

	if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
		return (0);
	pixel = texture->addr + (y * texture->line_length + x
			* (texture->bits_per_pixel / 8));
	return (*(unsigned int *)pixel);
}

void	init_textures(t_cube *cube)
{
	char	*path[4];
	int		i;

	i = 0;
	path[1] = cube->map.ea;
	path[0] = cube->map.no;
	path[2] = cube->map.se;
	path[3] = cube->map.we;
	while (i < 4)
	{
		cube->texture[i].img = mlx_xpm_file_to_image(cube->mlx, path[i],
				&cube->texture[i].width, &cube->texture[i].height);
		if (!cube->texture[i].img)
		{
			print_error(RED "failed to load textures\n" RESET);
			return ;
		}
		cube->texture[i].addr = mlx_get_data_addr(cube->texture[i].img,
				&cube->texture[i].bits_per_pixel, &cube->texture[i].line_length,
				&cube->texture[i].endian);
		if (!cube->texture[i].addr)
			return ;
		i++;
	}
}


static void	push_intro_frame(t_intro_frame **frames, void *img, int w, int h)
{
    t_intro_frame *new_frame = malloc(sizeof(t_intro_frame));
    t_intro_frame *current;

    new_frame->img = img;
    new_frame->width = w;
    new_frame->height = h;
    new_frame->next = NULL;
    if (!*frames)
    {
        *frames = new_frame;
        return;
    }
    current = *frames;
    while (current->next)
        current = current->next;
    current->next = new_frame;
}

/**
 * Loads XPM frames from “1.xpm” to “17.xpm” and stores them in a linked list.
 */
void	load_intro_frames(t_cube *cube, t_intro_frame **frames)
{
    char	path[128];
    int		i;
    void	*img;
    int		w, h;

    i = 1;
    while (i <= 17)
    {
        snprintf(path, sizeof(path), "./textures/intro/%d.xpm", i);
        img = mlx_xpm_file_to_image(cube->mlx, path, &w, &h);
        if (img)
            push_intro_frame(frames, img, w, h);
        i++;
    }
}

/**
 * Loads XPM frames from "5.xpm" to "27.xpm" and stores them in a linked list.
 */
void	load_second_intro_frames(t_cube *cube, t_intro_frame **frames)
{
    char	path[128];
    int		i;
    void	*img;
    int		w, h;

    i = 5;
    while (i <= 27)
    {
        snprintf(path, sizeof(path), "./textures/intro2/%d.xpm", i);
        img = mlx_xpm_file_to_image(cube->mlx, path, &w, &h);
        if (img)
            push_intro_frame(frames, img, w, h);
        i++;
    }
}

void	show_intro_animation(t_cube *cube, t_intro_frame *frames)
{
    t_intro_frame *current = frames;
    int	i = 0;

    cube->intro_timer++;
    if (cube->intro_timer < 10000)  // Wait for frame delay
        return;
    
    cube->intro_timer = 0;  // Reset timer
    
    while (current && i < cube->intro_frame_counter)
    {
        current = current->next;
        i++;
    }
    if (!current) 
    {
        current = frames;
        while (current->next)
            current = current->next;
    }
    else
    {
        cube->intro_frame_counter++;
    }
    clean_display(cube);
    mlx_put_image_to_window(cube->mlx, cube->mlx_window, current->img, 0, 0);
}

void	show_second_intro_animation(t_cube *cube, t_intro_frame *frames)
{
    t_intro_frame *current = frames;
    int	i = 0;

    cube->intro_timer++;
    if (cube->intro_timer < 10000)  // Wait for frame delay
        return;
    
    cube->intro_timer = 0;  // Reset timer
    
    while (current && i < cube->intro_frame_counter)
    {
        current = current->next;
        i++;
    }
    if (!current) 
    {
        // Second intro finished, enter game
        cube->intro_mode = 0;
        cube->intro_frame_counter = 0; // Reset for next time
        return;
    }
    else
    {
        cube->intro_frame_counter++;
    }
    clean_display(cube);
    mlx_put_image_to_window(cube->mlx, cube->mlx_window, current->img, 0, 0);
}

void show_intro(t_cube *cube, t_intro_frame *frames)
{
    // If not loaded yet, load all frames into cube->first_intro_frames
	(void)frames;
    if (!cube->first_intro_frames)
        load_intro_frames(cube, &cube->first_intro_frames);
    show_intro_animation(cube, cube->first_intro_frames);
    cube->intro_mode = 1;
}

void show_second_intro(t_cube *cube, t_intro_frame *frames)
{
    // If not loaded yet, load all frames
	(void)frames;
    if (!cube->second_intro_frames)
        load_second_intro_frames(cube, &cube->second_intro_frames);
    show_second_intro_animation(cube, cube->second_intro_frames);
}

void	mlx_hook_cube(t_cube *cube)
{
	// MiniLibX hook callbacks use an untyped function-pointer signature.
	// Cast to silence incompatible pointer type warnings.
	mlx_hook(cube->mlx_window, 17, 1L << 17, (int (*)())close_win, cube);
	mlx_hook(cube->mlx_window, 2, 1L << 0, (int (*)())on_key_press, cube);
	mlx_hook(cube->mlx_window, 3, 1L << 1, (int (*)())on_key_release, cube);
}

static int init_audio(void)
{
    if (SDL_Init(SDL_INIT_AUDIO) < 0)
        return (fprintf(stderr,"SDL_Init error\n"), 0);
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
        return (fprintf(stderr,"Mix_OpenAudio error\n"), 0);
    return 1;
}

void	game_engine(t_cube *cube)
{
	init_textures(cube);
	cube->sky.sky_img = mlx_xpm_file_to_image(cube->mlx, "textures/sky.xpm", &cube->sky.sky_width, &cube->sky.sky_height);
	cube->sky.sky_pixels = (int *)mlx_get_data_addr(cube->sky.sky_img, &cube->sky.bpp, &cube->sky.size_line, &cube->sky.endian);
	// cube->ground.ground_img = mlx_xpm_file_to_image(cube->mlx, "textures/ground_text.xpm", &cube->ground.ground_width, &cube->ground.ground_height);
	// cube->ground.ground_pixels = (int *)mlx_get_data_addr(cube->ground.ground_img, &cube->ground.bpp, &cube->ground.size_line, &cube->ground.endian);
	load_frames(cube);
	add_frame_ls(cube);
	mlx_hook_cube(cube);
	init_minimap_params(cube);
	cast_away(cube);
	cube->bgm = Mix_LoadMUS("./textures/hamid-el-kasri-allal.mp3");
	if (cube->bgm)
    	Mix_PlayMusic(cube->bgm, -1);
	draw_weapon(cube);
	draw_circular_minimap(cube);
	mlx_put_image_to_window(cube->mlx, cube->mlx_window, cube->data->img, 0, 0);
	mlx_loop_hook(cube->mlx, (int (*)())key_loop, cube);
	mlx_loop(cube->mlx);
}

void	init_mlx(t_cube *cube, t_data *data)
{
	cube->mlx = mlx_init();
	if (cube->mlx == NULL)
	{
		print_error(RED "mlx_init failed\n" RESET);
		free_all(cube->gc);
		return ;
	}
	cube->mlx_window = mlx_new_window(cube->mlx, WIDTH, HEIGHT, "Cub3D");
	if (cube->mlx_window == NULL)
	{
		print_error(RED "mlx_window failed\n" RESET);
		return ;
	}
	data->img = mlx_new_image(cube->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
		&data->line_length, &data->endian);
		
	cube->intro_mode = 1; // Start with first intro
	cube->first_intro_frames = NULL;
	cube->second_intro_frames = NULL;
	cube->intro_frame_counter = 0;
	cube->intro_timer = 0;
	init_audio(); // Initialize SDL audio
	show_intro(cube, NULL);	 // Show intro frames if available
	game_engine(cube);
}
