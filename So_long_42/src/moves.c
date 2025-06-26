/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samurai0lava <samurai0lava@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:39:45 by iouhssei          #+#    #+#             */
/*   Updated: 2025/06/26 18:17:03 by samurai0lav      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	handle_moves2(t_data_solong *data, int new_x, int new_y)
{
	if (new_x >= 0 && new_x < data->map_width && new_y >= 0
		&& new_y < data->map_height && data->map[new_y][new_x] != '1')
	{
		if (data->map[new_y][new_x] != 'E')
		{
			if (data->map[new_y][new_x] == 'C')
			{
				data->map[new_y][new_x] = '0';
				data->collected++;
			}
			if (data->collected == data->collectibles)
				data->exit_open = 1;
			data->map[data->player_y][data->player_x] = '0';
			data->player_x = new_x;
			data->player_y = new_y;
			data->map[new_y][new_x] = 'P';
			data->moves++;
		}
		else if (data->map[new_y][new_x] == 'E' && data->exit_open == 1
			&& data->collected == data->collectibles)
		{
			ft_printf("YOU WON\n");
			exit(0);
		}
	}
}

int	handle_moves(int key, t_data_solong *data)
{
	int	new_x;
	int	new_y;

	new_x = data->player_x;
	new_y = data->player_y;
	if (key == 65307)
	{
		free_map(data);	
		mlx_clear_window(data->mlx, data->win);
		free(data->mlx);	
		exit(0);
	}
	else if (key == 119 || key == 65362)
		new_y -= 1;
	else if (key == 115 || key == 65364)
		new_y += 1;
	else if (key == 97 || key == 65361)
	{
		new_x -= 1;
		data->left_check = 1;
	}
	else if (key == 100 || key == 65363)
	{
		new_x += 1;
		data->left_check = 0;
	}
	handle_moves2(data, new_x, new_y);
	ft_printf("Number of moves: %d\n", data->moves);
	draw_map(data);
	return (0);
}
