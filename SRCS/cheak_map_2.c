/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheak_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:16:17 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/12/05 17:45:23 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

char	cheak_up(t_pos pos_obj, char **data_path)
{
	char	c;

	pos_obj.y--;
	c = data_path[pos_obj.y][pos_obj.x];
	if (c == '0' || c == 'E' || c == 'e' || c == 'C' || c == 'P')
	{
		if (data_path[pos_obj.y][pos_obj.x] == 'P')
			return ('P');
		if (cheak_pathinmap(pos_obj, data_path) == 'P')
			return ('P');
	}
	return ('N');
}

char	cheak_down(t_pos pos_obj, char **data_path)
{
	char	c;

	pos_obj.y++;
	c = data_path[pos_obj.y][pos_obj.x];
	if (c == '0' || c == 'E' || c == 'e' || c == 'C' || c == 'P')
	{
		if (data_path[pos_obj.y][pos_obj.x] == 'P')
			return ('P');
		if (cheak_pathinmap(pos_obj, data_path) == 'P')
			return ('P');
	}
	return ('N');
}

char	cheak_left(t_pos pos_obj, char **data_path)
{
	char	c;

	pos_obj.x++;
	c = data_path[pos_obj.y][pos_obj.x];
	if (c == '0' || c == 'E' || c == 'e' || c == 'C' || c == 'P')
	{
		if (data_path[pos_obj.y][pos_obj.x] == 'P')
			return ('P');
		if (cheak_pathinmap(pos_obj, data_path) == 'P')
			return ('P');
	}
	return ('N');
}

char	cheak_right(t_pos pos_obj, char **data_path)
{
	char	c;

	pos_obj.x--;
	c = data_path[pos_obj.y][pos_obj.x];
	if (c == '0' || c == 'E' || c == 'e' || c == 'C' || c == 'P')
	{
		if (data_path[pos_obj.y][pos_obj.x] == 'P')
			return ('P');
		if (cheak_pathinmap(pos_obj, data_path) == 'P')
			return ('P');
	}
	return ('N');
}

char	cheak_pathinmap(t_pos pos_obj, char **data_path)
{
	data_path[pos_obj.y][pos_obj.x] = '-';
	if (cheak_up(pos_obj, data_path) == 'P')
		return ('P');
	if (cheak_down(pos_obj, data_path) == 'P')
		return ('P');
	if (cheak_left(pos_obj, data_path) == 'P')
		return ('P');
	if (cheak_right(pos_obj, data_path) == 'P')
		return ('P');
	return ('N');
}
