/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:26:23 by iouhssei          #+#    #+#             */
/*   Updated: 2024/06/13 10:26:27 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (1);
}
int	load_images(t_data *data)
{
	int	size;

	size = 32;
	data->img_ground = mlx_xpm_file_to_image(data->mlx, "assets/stand.xpm",
			&size, &size);
	data->img_wall = mlx_xpm_file_to_image(data->mlx, "assets/wall.xpm", &size,
			&size);
	data->img_player = mlx_xpm_file_to_image(data->mlx, "assets/lfariss.xpm",
			&size, &size);
	data->img_collectible = mlx_xpm_file_to_image(data->mlx,
			"assets/collect.xpm", &size, &size);
	data->img_exit = mlx_xpm_file_to_image(data->mlx, "assets/exit_close.xpm",
			&size, &size);
	data->img_exit_open = mlx_xpm_file_to_image(data->mlx,
			"assets/exit_open.xpm", &size, &size);
	data->fariss_left = mlx_xpm_file_to_image(data->mlx,
			"assets/fariss_left.xpm", &size, &size);
	if (!data->img_ground || !data->img_wall || !data->img_player
		|| !data->img_collectible || !data->img_exit || !data->img_exit_open
		|| !data->fariss_left)
	{
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2 && parsing_input(argv[1]))
	{
		if (initialize_data(&data) == 1)
			return (1);
		if (load_and_validate_map(&data, argv[1]) == 1)
			return (1);
		if (create_window(&data) == 1)
			return (1);
		if (setup_game(&data) == 1)
			return (1);
		mlx_hook(data.win, 17, 0, close_window, &data);
		mlx_key_hook(data.win, handle_moves, &data);
		mlx_loop(data.mlx);
	}
	else
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	return (0);
}
