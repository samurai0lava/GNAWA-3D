/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:23:49 by iouhssei          #+#    #+#             */
/*   Updated: 2024/06/13 10:24:10 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;
typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img_ground;
	void	*img_wall;
	void	*img_player;
	void	*img_collectible;
	void	*img_exit;
	void	*img_exit_open;
	void	*fariss_left;
	int		map_width;
	int		map_height;
	char	**map;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		collected;
	int		exit_open;
	int		left_check;
	int		moves;
	int		exit_found;
	int		collectible_found;
	int		player_count;
	int		exit_count;
	int		collectible_count;
	t_point	exit_pos;
}			t_data;

int			parsing_input(char *argv);
void		draw_map(t_data *data);
char		**load_map(const char *filename, int *height, t_data *data);
int			load_images(t_data *data);
int			handle_moves(int key, t_data *data);
int			check_map(t_data *data);
void		flood_fill(int x, int y, char **map, t_data *data);
void		data_init(t_data *data);
void		game_start(t_data data);
void		free_map(t_data *data);
void		free_map_1(char **map, int height);
void		player_check(t_data *data);
int			initialize_data(t_data *data);
int			load_and_validate_map(t_data *data, char *map_file);
int			create_window(t_data *data);
int			setup_game(t_data *data);
int			calculate_map_dimensions(const char *filename, t_data *data);
int			close_window(t_data *data);

#endif
