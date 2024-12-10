/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheak_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:58:27 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/12/09 10:14:26 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

int	cheak_howmanyexit_and_starting_carrot(t_pos size, t_vars *data_g)
{
	t_var_cheak	all;

	all = inisialyse();
	while (data_g->g_data[all.y])
	{
		all.x = -1;
		while (data_g->g_data[all.y][++all.x] && \
				data_g->g_data[all.y][all.x] != '\n')
		{
			if ((all.y == 0 || all.y == size.y - 1 || all.x == 0 || \
		all.x == size.x - 1) && data_g->g_data[all.y][all.x] != '1')
				return (5);
			if (data_g->g_data[all.y][all.x] == 'P')
				all.n_start++;
			else if (data_g->g_data[all.y][all.x] == 'C')
				all.n_carrot++;
			else if (data_g->g_data[all.y][all.x] == 'E')
				all.n_exit++;
			else if (data_g->g_data[all.y][all.x] != '1' && data_g->g_data \
			[all.y][all.x] != '0' && data_g->g_data[all.y][all.x] != 'I')
				return (0);
		}
		all.y++;
	}
	return (all.n_carrot != 0 && all.n_start == 1 && all.n_exit == 1);
}

char	**get_me_data_path(t_pos size, t_vars *data_g)
{
	t_pos	pos;
	char	**data_path;

	pos.x = 0;
	pos.y = 0;
	data_path = malloc(sizeof(char *) * (size.y));
	if (data_path == 0)
		return (NULL);
	while (pos.y < size.y)
	{
		data_path[pos.y] = ft_strdup(data_g->g_data[pos.y]);
		pos.y++;
	}
	return (data_path);
}

void	free_data(char **data_var, t_pos size)
{
	int	y;

	y = 0;
	while (y < size.y)
	{
		free(data_var[y]);
		y++;
	}
	free(data_var);
}

int	cheakpath_is_valid(t_pos size, t_vars *data_g)
{
	t_pos	pos;
	char	**data_path;

	pos.y = 0;
	data_path = get_me_data_path(size, data_g);
	while (pos.y < size.y)
	{
		pos.x = 0;
		while (pos.x < size.x)
		{
			if (data_g->g_data[pos.y][pos.x] == 'C' || data_g->\
			g_data[pos.y][pos.x] == 'E' || data_g->g_data[pos.y][pos.x] == 'I')
			{
				if (data_path == NULL)
					return (-1);
				if (cheak_pathinmap(pos, data_path) == 'N')
					return (free_data(data_path, size), 0);
				free_data(data_path, size);
				data_path = get_me_data_path(size, data_g);
			}
			pos.x++;
		}
		pos.y++;
	}
	return (free_data(data_path, size), 1);
}

void	set_foxes_in_tab_util(t_vars *data_g)
{
	t_pos	index;
	int		count;

	count = 0;
	index = (t_pos){0, 0};
	while (index.y < data_g->size.y)
	{
		index.x = 0;
		while (index.x < data_g->size.x)
		{
			if (data_g->g_data[index.y][index.x] == 'I')
			{
				data_g->foxes[count++] = index;
				data_g->g_data[index.y][index.x] = '0';
			}
			index.x++;
		}
		index.y++;
	}
}
