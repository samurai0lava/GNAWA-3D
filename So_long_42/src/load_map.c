/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:26:06 by iouhssei          #+#    #+#             */
/*   Updated: 2024/06/13 10:26:12 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static char	**allocate_map_memory(t_data *data)
{
	char	**map;

	map = (char **)malloc(sizeof(char *) * (data->map_height + 1));
	if (!map)
		return (NULL);
	return (map);
}

static void	count_collectibles(const char *line, t_data *data)
{
	int	j;

	j = 0;
	while (line[j])
	{
		if (line[j] == 'C')
			data->collectibles++;
		j++;
	}
}

static int	process_map_line(char **map, char *line, int i, t_data *data)
{
	size_t	len;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
	map[i] = ft_strdup(line);
	if (!map[i])
		return (-1);
	count_collectibles(map[i], data);
	return (0);
}

static int	load_map_content(const char *filename, char **map, t_data *data)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (process_map_line(map, line, i, data) < 0)
		{
			free(line);
			free_map_1(map, i);
			close(fd);
			return (-1);
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	map[i] = NULL;
	close(fd);
	return (0);
}

char	**load_map(const char *filename, int *height, t_data *data)
{
	char	**map;

	if (calculate_map_dimensions(filename, data) < 0)
		return (NULL);
	map = allocate_map_memory(data);
	if (!map)
		return (NULL);
	if (load_map_content(filename, map, data) < 0)
	{
		free(map);
		return (NULL);
	}
	*height = data->map_height;
	return (map);
}
