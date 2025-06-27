/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samurai0lava <samurai0lava@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:27:09 by iouhssei          #+#    #+#             */
/*   Updated: 2025/06/26 23:42:47 by samurai0lav      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	initialize_data(t_data_solong *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (1);
	data_init(data);
	return (0);
}

int	load_and_validate_map(t_data_solong *data, char *map_file)
{
	data->map = load_map(map_file, &data->map_height, data);
	if (!data->map)
	{
		free(data->mlx);
		return (1);
	}
	if (check_map_solong(data) == 1)
	{
		ft_putendl_fd("Error", 2);
		free_map(data);
		free(data->mlx);
		return (1);
	}
	return (0);
}

int	create_window(t_data_solong *data)
{
	data->win = mlx_new_window(data->mlx, data->map_width * 32, data->map_height
			* 32, "so_long");
	if (!data->win)
	{
		free(data->mlx);
		free_map(data);
		return (1);
	}
	return (0);
}

int	setup_game(t_data_solong *data)
{
	if (load_images(data) != 0)
		return (1);
	draw_map(data);
	return (0);
}

void	free_map(t_data_solong *data)
{
	int	i;

	i = 0;
	while (i < data->map_height)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}
