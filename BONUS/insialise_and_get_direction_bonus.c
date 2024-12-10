/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insialise_and_get_direction_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:45:02 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/12/09 11:44:22 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	insialise_part2(t_vars *data_g)
{
	t_pos		si;

	data_g->img_fox.fox_lefth[0] = mlx_xpm_file_to_image(data_g->mlx, \
					"sprites/fox/fox_left1.xpm", &si.y, &si.x);
	data_g->img_fox.fox_lefth[1] = mlx_xpm_file_to_image(data_g->mlx, \
						"sprites/fox/fox_left2.xpm", &si.y, &si.x);
	data_g->img_fox.fox_lefth[2] = mlx_xpm_file_to_image(data_g->mlx, \
						"sprites/fox/fox_left3.xpm", &si.y, &si.x);
	data_g->img_fox.fox_regth[0] = mlx_xpm_file_to_image(data_g->mlx, \
						"sprites/fox/fox_right1.xpm", &si.y, &si.x);
	data_g->img_fox.fox_regth[1] = mlx_xpm_file_to_image(data_g->mlx, \
						"sprites/fox/fox_right2.xpm", &si.y, &si.x);
	data_g->img_fox.fox_regth[2] = mlx_xpm_file_to_image(data_g->mlx, \
						"sprites/fox/fox_right3.xpm", &si.y, &si.x);
}

void	insialise_fox_img(t_vars *data_g)
{
	static int	i = 0;
	t_pos		si;

	if (i == 1)
		return ;
	i = 1;
	data_g->img_fox.ifinsilese = 1;
	data_g->img_fox.fox_down[0] = mlx_xpm_file_to_image(data_g->mlx, \
					"sprites/fox/fox_down1.xpm", &si.y, &si.x);
	data_g->img_fox.fox_down[1] = mlx_xpm_file_to_image(data_g->mlx, \
					"sprites/fox/fox_down2.xpm", &si.y, &si.x);
	data_g->img_fox.fox_down[2] = mlx_xpm_file_to_image(data_g->mlx, \
					"sprites/fox/fox_down3.xpm", &si.y, &si.x);
	data_g->img_fox.fox_up[0] = mlx_xpm_file_to_image(data_g->mlx, \
					"sprites/fox/fox_up1.xpm", &si.y, &si.x);
	data_g->img_fox.fox_up[1] = mlx_xpm_file_to_image(data_g->mlx, \
					"sprites/fox/fox_up2.xpm", &si.y, &si.x);
	data_g->img_fox.fox_up[2] = mlx_xpm_file_to_image(data_g->mlx, \
					"sprites/fox/fox_up3.xpm", &si.y, &si.x);
	insialise_part2(data_g);
}

void	set_img_for_enemy(t_pos p_to, char img, t_vars *data_g)
{
	static unsigned int	move = 0;

	p_to.x *= S_PX;
	p_to.y *= S_PX;
	if (img == 'U')
		mlx_put_image_to_window(data_g->mlx, data_g->win, \
			data_g->img_fox.fox_up[move % 3], p_to.x, p_to.y);
	if (img == 'D')
		mlx_put_image_to_window(data_g->mlx, data_g->win, \
			data_g->img_fox.fox_down[move % 3], p_to.x, p_to.y);
	if (img == 'L')
	{
		mlx_put_image_to_window(data_g->mlx, data_g->win, \
				data_g->img_fox.fox_lefth[move % 3], p_to.x, p_to.y);
	}
	if (img == 'R')
	{
		mlx_put_image_to_window(data_g->mlx, data_g->win, \
			data_g->img_fox.fox_regth[move % 3], p_to.x, p_to.y);
	}
	move++;
}

char	get_deriction(t_pos p_enemy, t_pos p_to)
{
	if (p_to.x - p_enemy.x == 1)
		return ('R');
	if (p_to.x - p_enemy.x == -1)
		return ('L');
	if (p_to.y - p_enemy.y == 1)
		return ('D');
	if (p_to.y - p_enemy.y == -1)
		return ('U');
	return ('0');
}
