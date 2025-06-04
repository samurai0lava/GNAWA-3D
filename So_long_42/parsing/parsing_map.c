/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:25:01 by iouhssei          #+#    #+#             */
/*   Updated: 2024/06/13 10:25:04 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_map_1(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	**copy_map(char **map, int width, int height)
{
	int		i;
	int		j;
	char	**new_map;

	new_map = malloc(sizeof(char *) * height);
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < height)
	{
		new_map[i] = malloc(sizeof(char) * (width + 1));
		if (!new_map[i])
		{
			free_map_1(map, height);
			return (NULL);
		}
		j = 0;
		while (j++ < width)
		{
			new_map[i][j] = map[i][j];
		}
		new_map[i][width] = '\0';
		i++;
	}
	return (new_map);
}

void	flood_fill(int x, int y, char **map, t_data *data)
{
	if (x < 0 || x >= data->map_width || y < 0 || y >= data->map_height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'E')
		data->exit_found = 1;
	if (map[y][x] == 'C')
		data->collectible_found = 1;
	map[y][x] = 'V';
	flood_fill(x + 1, y, map, data);
	flood_fill(x - 1, y, map, data);
	flood_fill(x, y + 1, map, data);
	flood_fill(x, y - 1, map, data);
}

int	check_border(char **map, int width, int height)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_map(t_data *data)
{
	char	**map_copy;

	data->exit_found = 0;
	data->player_count = 0;
	if (check_border(data->map, data->map_width, data->map_height) == 0)
	{
		return (1);
	}
	player_check(data);
	map_copy = copy_map(data->map, data->map_width, data->map_height);
	if (!map_copy)
		return (1);
	flood_fill(data->player_x, data->player_y, map_copy, data);
	free_map_1(map_copy, data->map_height);
	if (data->exit_found != 1 || data->collectible_found != 1
		|| data->player_count != 1)
		return (1);
	return (0);
}
