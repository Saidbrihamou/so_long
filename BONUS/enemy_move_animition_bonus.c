/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_animition_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:28:58 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/12/09 11:31:01 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

int	pos_move_eq_othe(t_vars *data_g, t_pos p_to)
{
	int	count;

	count = 0;
	while (data_g->count_foxes > count)
	{
		if (is_equal(data_g->foxes[count], p_to))
			return (0);
		count++;
	}
	return (1);
}

void	move_enemy(t_pos *p_enemy, t_pos p_to, t_vars *data_g)
{
	char	diriction;
	void	*mlx_win[3];

	if (is_equal(*p_enemy, p_to) || data_g->g_data[p_to.y][p_to.x] == 'P')
	{
		mlx_string_put(data_g->mlx, data_g->win, data_g->size.x * 50 / 2, \
				data_g->size.y * 50 / 2, 0xD4EBF8, "GAME OVER");
		data_g->game_over = 1;
	}
	if (pos_move_eq_othe(data_g, p_to) == 0)
		return ;
	mlx_win[0] = data_g->mlx;
	mlx_win[1] = data_g->win;
	insialise_fox_img(data_g);
	diriction = get_deriction(*p_enemy, p_to);
	set_img_in_map(mlx_win, '0', *p_enemy, data_g);
	if (data_g->g_data[p_enemy->y][p_enemy->x] == 'C')
		set_img_in_map(mlx_win, 'C', *p_enemy, data_g);
	if (is_equal(data_g->g_pos_door, *p_enemy) && data_g->g_count_carrot == 0)
		set_img_in_map(mlx_win, 'O', data_g->g_pos_door, data_g);
	else if (is_equal(data_g->g_pos_door, *p_enemy))
		set_img_in_map(mlx_win, 'E', data_g->g_pos_door, data_g);
	set_img_for_enemy(p_to, diriction, data_g);
	*p_enemy = p_to;
}

void	set_animition(t_vars	*data_g)
{
	t_pos				player_pos;
	void				*mlx_win[2];
	static unsigned int	move = 0;
	static clock_t		i;

	mlx_win[0] = data_g->mlx;
	mlx_win[1] = data_g->win;
	if ((clock() * 1000) / CLOCKS_PER_SEC < i + 15 || data_g->game_over == 1)
		return ;
	i = (clock() * 1000) / CLOCKS_PER_SEC;
	mlx_win[0] = data_g->mlx;
	mlx_win[1] = data_g->win;
	player_pos = get_me_pos_player_ordoor('P', data_g);
	set_img_in_map(mlx_win, '0', player_pos, data_g);
	mlx_put_image_to_window(data_g->mlx, data_g->win, \
	data_g->g_map.player[move % 7], player_pos.x * S_PX, player_pos.y * S_PX);
	move++;
}

void	cheak_en_player(t_vars *data_g)
{
	int		count;
	t_pos	player_pos;

	if (data_g->game_over == 1)
		return ;
	count = 0;
	player_pos = get_me_pos_player_ordoor('P', data_g);
	while (data_g->count_foxes > count)
	{
		if (is_equal(data_g->foxes[count], player_pos))
		{
			data_g->game_over = 1;
			mlx_string_put(data_g->mlx, data_g->win, data_g->size.x * 50 / 2, \
					data_g->size.y * 50 / 2, 0xD4EBF8, "GAME OVER");
		}
		count++;
	}
}

int	updata_move(t_vars	*data_g)
{
	t_pos			player_pos;
	int				index;
	static clock_t	i = 0;

	cheak_en_player(data_g);
	set_animition(data_g);
	if ((clock() * 1000) / CLOCKS_PER_SEC < i + 100)
		return (0);
	i = (clock() * 1000) / CLOCKS_PER_SEC;
	index = 0;
	player_pos = get_me_pos_player_ordoor('P', data_g);
	while (index < data_g->count_foxes && data_g->game_over == 0)
	{
		move_enemy(&data_g->foxes[index], get_pos_to_move(data_g, data_g->\
					foxes[index], player_pos), data_g);
		index++;
	}
	return (0);
}
