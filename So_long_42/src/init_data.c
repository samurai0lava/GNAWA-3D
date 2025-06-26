/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samurai0lava <samurai0lava@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:25:54 by iouhssei          #+#    #+#             */
/*   Updated: 2025/06/26 18:16:34 by samurai0lav      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	data_init(t_data_solong *data)
{
	data->left_check = -1;
	data->moves = 0;
	data->collected = 0;
	data->exit_open = 0;
	data->map_height = 0;
	data->map_width = 0;
	data->collectible_found = 0;
	data->exit_found = 0;
	data->player_count = 0;
	data->exit_count = 0;
	data->collectibles = 0;
}
