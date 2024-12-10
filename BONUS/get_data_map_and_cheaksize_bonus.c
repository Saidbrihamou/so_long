/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_map_and_cheaksize_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:21:18 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/12/08 12:07:25 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

t_pos	cheakis_valideand_countsize(char *filename)
{
	int		fd;
	char	*line;
	t_pos	size;
	t_pos	is_notvalide;

	is_notvalide.x = 0;
	is_notvalide.y = 0;
	size.x = 0;
	size.y = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (is_notvalide);
	line = get_next_line(fd);
	size.x = ft_strlen(line);
	while (line)
	{
		if (size.x != (int)ft_strlen(line))
			return (free(line), is_notvalide);
		free(line);
		line = get_next_line(fd);
		size.y++;
	}
	return (size);
}

char	**get_map_from_file(char *filename, t_pos *size, t_vars *data_g)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	*size = cheakis_valideand_countsize(filename);
	if (size->x == 0 || size->y == 0)
		return (NULL);
	data_g->g_data = malloc((size->y + 1) * sizeof(char *));
	if (data_g->g_data == NULL)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (free(data_g->g_data), NULL);
	line = get_next_line(fd);
	while (line)
	{
		data_g->g_data[i++] = line;
		line = get_next_line(fd);
	}
	data_g->g_data[i] = NULL;
	return (data_g->g_data);
}

void	count_total_carrot(t_vars *data_g)
{
	t_pos	index;

	index.x = 0;
	index.y = 0;
	data_g->g_count_carrot = 0;
	while (data_g->g_data[index.y])
	{
		index.x = 0;
		while (data_g->g_data[index.y][index.x])
		{
			if (data_g->g_data[index.y][index.x] == 'C')
				data_g->g_count_carrot++;
			index.x += 1;
		}
		index.y += 1;
	}
}
