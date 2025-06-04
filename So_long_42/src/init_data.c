/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:25:54 by iouhssei          #+#    #+#             */
/*   Updated: 2024/06/13 10:25:58 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	data_init(t_data *data)
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
