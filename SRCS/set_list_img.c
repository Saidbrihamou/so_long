/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_list_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:27:34 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/12/08 21:19:58 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	if_win(t_vars *data_g)
{
	data_g->youwin = 1;
	ft_putstr_fd("\nmove :", 1);
	ft_putnbr_fd(data_g->g_count_move, 1);
	ft_putstr_fd("\n=== YOU WIN !! ==", 1);
}

void	open_door( void *mlx_and_win[2], t_vars *data_g)
{
	set_img_in_map(mlx_and_win, '0', data_g->g_pos_door, data_g);
	set_img_in_map(mlx_and_win, 'O', data_g->g_pos_door, data_g);
}

void	set_img_for_ptr(void *mlx, t_vars *data_g)
{
	static int	i = 0;
	t_pos		size;

	if (i == 1)
		return ;
	i = 1;
	data_g->g_map.wall = mlx_xpm_file_to_image(mlx, \
			"sprites/wall.xpm", &size.x, &size.y);
	data_g->g_map.player = mlx_xpm_file_to_image(mlx, \
			"sprites/p_xpm/p1.xpm", &size.x, &size.y);
	data_g->g_map.collectible = mlx_xpm_file_to_image(mlx, \
			"sprites/key.xpm", &size.x, &size.y);
	data_g->g_map.empty_space = mlx_xpm_file_to_image(mlx, \
			"sprites/tile.xpm", &size.x, &size.y);
	data_g->g_map.exit_map_open = mlx_xpm_file_to_image(mlx, \
					"sprites/door_open50.xpm", &size.x, &size.y);
	data_g->g_map.exit_map_close = mlx_xpm_file_to_image(mlx, \
				"sprites/door_close50.xpm", &size.x, &size.y);
}

void	set_img_in_map(void *mlx_and_win[3], char img, \
									t_pos pos, t_vars *data_g)
{
	pos.x *= S_PX;
	pos.y *= S_PX;
	set_img_for_ptr(mlx_and_win[0], data_g);
	if (img == '0')
		mlx_put_image_to_window(mlx_and_win[0], \
			mlx_and_win[1], data_g->g_map.empty_space, pos.x, pos.y);
	if (img == '1')
		mlx_put_image_to_window(mlx_and_win[0], \
			mlx_and_win[1], data_g->g_map.wall, pos.x, pos.y);
	if (img == 'C')
		mlx_put_image_to_window(mlx_and_win[0], \
			mlx_and_win[1], data_g->g_map.collectible, pos.x, pos.y);
	if (img == 'E')
		mlx_put_image_to_window(mlx_and_win[0], \
			mlx_and_win[1], data_g->g_map.exit_map_close, pos.x, pos.y);
	if (img == 'O')
		mlx_put_image_to_window(mlx_and_win[0], \
			mlx_and_win[1], data_g->g_map.exit_map_open, pos.x, pos.y);
	if (img == 'P')
		mlx_put_image_to_window(mlx_and_win[0], \
			mlx_and_win[1], data_g->g_map.player, pos.x, pos.y);
}

void	set_map(void *mlx_and_win[3], t_pos size, t_vars *data_g)
{
	t_pos	pos;
	int		i;

	i = 0;
	pos.x = 0;
	pos.y = 0;
	set_img_for_ptr(mlx_and_win[0], data_g);
	while (pos.y < size.y)
	{
		pos.x = 0;
		while (pos.x < size.x)
		{
			mlx_put_image_to_window(mlx_and_win[0], mlx_and_win[1], \
				data_g->g_map.empty_space, pos.x * S_PX, pos.y * S_PX);
			set_img_in_map(mlx_and_win, data_g->g_data[pos.y][pos.x], \
															pos, data_g);
			pos.x += 1;
		}
		pos.y += 1;
	}
}
