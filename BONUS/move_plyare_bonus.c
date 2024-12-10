/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_plyare_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:39:47 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/12/09 12:56:28 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

t_pos	get_me_pos_player_ordoor(char p_or_e, t_vars *g_data)
{
	t_pos	index;

	index.x = 0;
	index.y = 0;
	while (g_data->g_data[index.y])
	{
		index.x = 0;
		while (g_data->g_data[index.y][index.x])
		{
			if (g_data->g_data[index.y][index.x] == p_or_e)
			{
				if (p_or_e == 'E')
					g_data->g_data[index.y][index.x] = '0';
				return (index);
			}
			index.x += 1;
		}
		index.y += 1;
	}
	return (index);
}

void	put_number_move(t_vars *data_g, void *mlx_win[3])
{
	char	*count_move;

	set_img_in_map(mlx_win, '0', (t_pos){0, 0}, data_g);
	set_img_in_map(mlx_win, '0', (t_pos){1, 0}, data_g);
	set_img_in_map(mlx_win, '0', (t_pos){2, 0}, data_g);
	set_img_in_map(mlx_win, '1', (t_pos){0, 0}, data_g);
	set_img_in_map(mlx_win, '1', (t_pos){1, 0}, data_g);
	set_img_in_map(mlx_win, '1', (t_pos){2, 0}, data_g);
	mlx_string_put(data_g->mlx, data_g->win, 15, 15, 0xD4EBF8, "move :");
	count_move = ft_itoa(data_g->g_count_move);
	mlx_string_put(data_g->mlx, data_g->win, 76, 15, 0xD4EBF8, count_move);
	free(count_move);
}

void	cheak_the_door(t_pos pos_player, t_pos pos_move, void *mlx_and_win[3])
{
	t_vars	*data_g;

	data_g = mlx_and_win[2];
	if (is_equal(data_g->g_pos_door, pos_player) && data_g->g_count_carrot == 0)
		set_img_in_map(mlx_and_win, 'O', data_g->g_pos_door, data_g);
	else if (is_equal(data_g->g_pos_door, pos_player))
		set_img_in_map(mlx_and_win, 'E', data_g->g_pos_door, data_g);
	if (pos_move.x == data_g->g_pos_door.x && \
							pos_move.y == data_g->g_pos_door.y)
	{
		data_g->g_count_move++;
		if (data_g->g_count_carrot == 0)
		{
			data_g->game_over = 1;
			put_number_move(data_g, mlx_and_win);
			mlx_string_put(data_g->mlx, data_g->win, data_g->size.x * 50 / 2, \
					data_g->size.y * 50 / 2, 0xD4EBF8, "YOU WIN!");
		}
		set_img_in_map(mlx_and_win, '0', pos_player, data_g);
		set_img_in_map(mlx_and_win, 'P', pos_move, data_g);
		data_g->g_data[pos_player.y][pos_player.x] = '0';
		data_g->g_data[pos_move.y][pos_move.x] = 'P';
	}
	put_number_move(data_g, mlx_and_win);
}

void	move_any_where(t_pos pos_player, t_pos pos_move, \
									void *mlx_and_win[3], t_vars *data_g)
{
	if (data_g->g_data[pos_move.y][pos_move.x] == '1')
		return ;
	if (data_g->g_data[pos_move.y][pos_move.x] == 'C')
	{
		data_g->g_count_carrot--;
		data_g->g_count_move++;
		if (data_g->g_count_carrot == 0)
			open_door(mlx_and_win, data_g);
		set_img_in_map(mlx_and_win, '0', pos_player, data_g);
		set_img_in_map(mlx_and_win, '0', pos_move, data_g);
		set_img_in_map(mlx_and_win, 'P', pos_move, data_g);
		data_g->g_data[pos_player.y][pos_player.x] = '0';
		data_g->g_data[pos_move.y][pos_move.x] = 'P';
	}
	if (data_g->g_data[pos_move.y][pos_move.x] == '0')
	{
		if (!is_equal(data_g->g_pos_door, pos_move))
			data_g->g_count_move++;
		set_img_in_map(mlx_and_win, '0', pos_player, data_g);
		set_img_in_map(mlx_and_win, 'P', pos_move, data_g);
		data_g->g_data[pos_player.y][pos_player.x] = '0';
		data_g->g_data[pos_move.y][pos_move.x] = 'P';
	}
	cheak_the_door(pos_player, pos_move, mlx_and_win);
}

int	handle_key(int key, void *mlx_and_win_data[3])
{
	t_pos	pos_player;
	t_pos	pos_move;
	t_vars	*data_g;

	data_g = mlx_and_win_data[2];
	if (key == 53)
		exit_and_free(mlx_and_win_data[0], mlx_and_win_data[1], data_g);
	else if (data_g->game_over)
		return (0);
	pos_player = get_me_pos_player_ordoor('P', data_g);
	pos_move = pos_player;
	if (key == 126)
		pos_move.y--;
	else if (key == 124)
		pos_move.x++;
	else if (key == 125)
		pos_move.y++;
	else if (key == 123)
		pos_move.x--;
	else
		return (0);
	return (move_any_where(pos_player, pos_move, mlx_and_win_data, data_g), 0);
}
