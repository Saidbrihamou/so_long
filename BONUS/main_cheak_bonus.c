/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cheak_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:14:18 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/12/09 10:17:02 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	set_foxes_in_tab(t_vars *data_g)
{
	t_pos	index;

	data_g->count_foxes = 0;
	index = (t_pos){0, 0};
	while (index.y < data_g->size.y)
	{
		index.x = 0;
		while (index.x < data_g->size.x)
		{
			if (data_g->g_data[index.y][index.x] == 'I')
				data_g->count_foxes++;
			index.x++;
		}
		index.y++;
	}
	data_g->foxes = malloc(sizeof(t_pos) * data_g->count_foxes);
	if (data_g->foxes == NULL)
		exit_with_error("Error\nNo memory !!", data_g->size, data_g);
	set_foxes_in_tab_util(data_g);
}

void	cheak_size_and_rect(t_vars *data_g, char *filename)
{
	data_g->g_data = get_map_from_file(filename, &data_g->size, data_g);
	if (data_g->g_data == NULL)
		exit_with_error("Please check if your map file is \
		in .ber format or if the map is rectangular\n", data_g->size, data_g);
	if (cheak_howmanyexit_and_starting_carrot(data_g->size, data_g) == 0)
		exit_with_error("The map must contain 1 exit, at least \
	1 collectible,and 1 starting position to be valid.\n", \
								data_g->size, data_g);
	if (cheak_howmanyexit_and_starting_carrot(data_g->size, data_g) == 5)
		exit_with_error("The map must be closed\n", data_g->size, data_g);
	if (data_g->size.x > 163 || data_g->size.y > 163)
		exit_with_error("Please the max size is 163 for length and width!!\n", \
					data_g->size, data_g);
}

void	main_cheak(char *filename, t_vars *data_g)
{
	int	ispath;
	int	i;

	i = ft_strlen(filename);
	if (i >= 4 && (filename[i - 1] != 'r' || filename[i - 2] != 'e' || \
				filename[i - 3] != 'b' || filename[i - 4] != '.'))
	{
		ft_putstr_fd("Error\nPlease cheak the file is in .ber format.", 2);
		exit(1);
	}
	cheak_size_and_rect(data_g, filename);
	ispath = cheakpath_is_valid(data_g->size, data_g);
	if (ispath == 0)
		exit_with_error("the path in the map is not valid\n", \
						data_g->size, data_g);
	if (ispath == -1)
		exit_with_error("Error\nNo memory !!", data_g->size, data_g);
	set_foxes_in_tab(data_g);
}
