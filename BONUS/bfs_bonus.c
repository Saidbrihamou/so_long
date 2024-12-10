/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:32:15 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/12/09 11:32:53 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	insialise_move(t_pos *move)
{
	move[0] = (t_pos){1, 0};
	move[1] = (t_pos){0, 1};
	move[2] = (t_pos){-1, 0};
	move[3] = (t_pos){0, -1};
}

t_data_bfs	bfs(char **data, t_pos size, t_pos start_end[2], t_vars	*data_g)
{
	t_data_bfs	vars;
	t_pos		move[4];

	insialise_move(move);
	insialyse_t_data(&vars, size, start_end[0]);
	while (vars.back > vars.front)
	{
		vars.courrent = vars.queue[vars.front++];
		if (vars.courrent.x == start_end[1].x && \
				vars.courrent.y == start_end[1].y)
		{
			return (vars);
		}
		if (is_pos_allowed(data, pos_add(vars.courrent, move[0]), data_g))
			add_in_queue(&vars, pos_add(vars.courrent, move[0]), vars.courrent);
		if (is_pos_allowed(data, pos_add(vars.courrent, move[1]), data_g))
			add_in_queue(&vars, pos_add(vars.courrent, move[1]), vars.courrent);
		if (is_pos_allowed(data, pos_add(vars.courrent, move[2]), data_g))
			add_in_queue(&vars, pos_add(vars.courrent, move[2]), vars.courrent);
		if (is_pos_allowed(data, pos_add(vars.courrent, move[3]), data_g))
			add_in_queue(&vars, pos_add(vars.courrent, move[3]), vars.courrent);
	}
	return (vars);
}

void	free_data_bfs(t_data_bfs d_bfs, t_pos size)
{
	int	index;

	index = 0;
	while (index < size.y)
	{
		free(d_bfs.prev[index]);
		index++;
	}
	free(d_bfs.prev);
	free(d_bfs.queue);
}

t_pos	get_pos_to_move(t_vars *data_g, t_pos start, t_pos end)
{
	char		**data;
	t_data_bfs	d_bfs;
	t_pos		last_open;
	t_pos		start_end[2];

	start_end[0] = start;
	start_end[1] = end;
	data = get_me_data_path(data_g->size, data_g);
	if (data == NULL)
		exit(1);
	d_bfs = bfs(data, data_g->size, start_end, data_g);
	free_data(data, data_g->size);
	last_open = d_bfs.queue[d_bfs.front - 1];
	if (is_equal(last_open, start_end[1]))
	{
		while (is_equal(d_bfs.prev[last_open.y][last_open.x], \
				start_end[0]) != 1)
		{
			last_open = d_bfs.prev[last_open.y][last_open.x];
		}
		free_data_bfs(d_bfs, data_g->size);
		return (last_open);
	}
	free_data_bfs(d_bfs, data_g->size);
	return (start_end[0]);
}
