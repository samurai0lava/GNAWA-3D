/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:26:53 by iouhssei          #+#    #+#             */
/*   Updated: 2024/06/13 10:26:56 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	calculate_map_dimensions(const char *filename, t_data *data)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	data->map_width = 0;
	data->map_height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (data->map_width == 0)
			data->map_width = ft_strlen(line) - 1;
		(data->map_height)++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

void	player_check(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->map[i][j] == 'P')
			{
				data->player_x = j;
				data->player_y = i;
				data->player_count++;
			}
			j++;
		}
		i++;
	}
}
