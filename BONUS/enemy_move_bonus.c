/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:20:24 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/12/09 10:29:36 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	insialyse_t_data(t_data_bfs *vars, t_pos size, t_pos start)
{
	int	y;

	vars->front = 0;
	vars->back = 0;
	vars->prev = malloc(sizeof(t_pos *) * size.y);
	y = 0;
	while (y < size.y)
	{
		vars->prev[y] = malloc(sizeof(t_pos) * size.x);
		y++;
	}
	vars->queue = malloc(sizeof(t_pos) * (size.y * size.x));
	vars->queue[vars->back++] = start;
	vars->prev[start.y][start.x] = (t_pos){-1, -1};
}

int	is_pos_allowed(char **data, t_pos pos, t_vars *data_g)
{
	char	p;

	p = data[pos.y][pos.x];
	if (p == '-')
	{
		return (0);
	}
	if (p == 'P' || p == '0' || p == 'C' || p == 'I' || \
		(data_g->g_pos_door.x == pos.x && data_g->g_pos_door.y == pos.y))
	{
		data[pos.y][pos.x] = '-';
		return (1);
	}
	return (0);
}

t_pos	pos_add(t_pos p1, t_pos p2)
{
	return ((t_pos){p1.x + p2.x, p1.y + p2.y});
}

void	add_in_queue(t_data_bfs *vars, t_pos pos, t_pos pos_father)
{
	vars->queue[vars->back++] = pos;
	vars->prev[pos.y][pos.x] = pos_father;
}

int	is_equal(t_pos p1, t_pos p2)
{
	return (p1.x == p2.x && p1.y == p2.y);
}
