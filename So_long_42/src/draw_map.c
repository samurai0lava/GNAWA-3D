/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samurai0lava <samurai0lava@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:25:25 by iouhssei          #+#    #+#             */
/*   Updated: 2025/06/26 18:16:25 by samurai0lav      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	draw_static_element(t_data_solong *data, int x, int y)
{
	if (data->map[y][x] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->img_ground, x
			* 32, y * 32);
	else if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->img_wall, x
			* 32, y * 32);
	else if (data->map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->img_collectible, x
			* 32, y * 32);
	else if (data->map[y][x] == 'E')
	{
		if (data->exit_open == 0)
			mlx_put_image_to_window(data->mlx, data->win, data->img_exit, x
				* 32, y * 32);
		else if (data->exit_open == 1)
			mlx_put_image_to_window(data->mlx, data->win, data->img_exit_open, x
				* 32, y * 32);
	}
}

static void	draw_dynamic_element(t_data_solong *data, int x, int y)
{
	if (data->map[y][x] == 'P')
	{
		if (data->left_check == -1 || data->left_check == 0)
			mlx_put_image_to_window(data->mlx, data->win, data->img_player, x
				* 32, y * 32);
		else if (data->left_check == 1)
			mlx_put_image_to_window(data->mlx, data->win, data->fariss_left, x
				* 32, y * 32);
	}
}

static void	draw_element(t_data_solong *data, int x, int y)
{
	draw_static_element(data, x, y);
	draw_dynamic_element(data, x, y);
}

static void	draw_map_row(t_data_solong *data, int y)
{
	int	x;

	x = 0;
	while (x < data->map_width)
	{
		draw_element(data, x, y);
		x++;
	}
}

void	draw_map(t_data_solong *data)
{
	int	y;

	y = 0;
	while (y < data->map_height)
	{
		draw_map_row(data, y);
		y++;
	}
}
