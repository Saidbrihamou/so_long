/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chaek_size_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:22:12 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/12/09 12:50:22 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	cheak_size_and_rect(t_vars *data_g, char *filename, t_pos *size)
{
	data_g->g_data = get_map_from_file(filename, size, data_g);
	if (data_g->g_data == NULL)
		exit_with_error("Please check if your map file is \
in .ber format or if the map is rectangular\n", *size, data_g);
	if (cheak_howmanyexit_and_starting_carrot(*size, data_g) == 0)
		exit_with_error("The map must contain 1 exit, at least \
		1 collectible,and 1 starting position to be valid.\n", *size, data_g);
	if (cheak_howmanyexit_and_starting_carrot(*size, data_g) == 5)
		exit_with_error("The map must be closed\n", *size, data_g);
	if (size->x > 163 || size->y > 163)
		exit_with_error("Please the max size is 163 for length and width!!\n", \
					*size, data_g);
}

int	is_equal(t_pos p1, t_pos p2)
{
	return (p1.x == p2.x && p1.y == p2.y);
}
