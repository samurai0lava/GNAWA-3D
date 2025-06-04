/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:24:43 by iouhssei          #+#    #+#             */
/*   Updated: 2024/06/13 10:24:49 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	check_ext(char *str)
{
	int		len;
	char	*ext;

	ext = ".ber";
	len = ft_strlen(str);
	if (len <= 4)
		return (0);
	if (ft_strncmp(str + len - 4, ext, 4) == 0)
		return (1);
	else
		return (0);
}

int	parsing_input(char *argv)
{
	if (check_ext(argv) == 0)
		return (0);
	return (1);
}
