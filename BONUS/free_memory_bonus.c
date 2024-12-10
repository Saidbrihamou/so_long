/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:41:20 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/12/09 13:07:35 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	distroy_image_player(t_vars *data_g)
{
	mlx_destroy_image(data_g->mlx, data_g->g_map.player[0]);
	mlx_destroy_image(data_g->mlx, data_g->g_map.player[1]);
	mlx_destroy_image(data_g->mlx, data_g->g_map.player[2]);
	mlx_destroy_image(data_g->mlx, data_g->g_map.player[3]);
	mlx_destroy_image(data_g->mlx, data_g->g_map.player[4]);
	mlx_destroy_image(data_g->mlx, data_g->g_map.player[5]);
	mlx_destroy_image(data_g->mlx, data_g->g_map.player[6]);
}

void	distroy_image_foxs(t_vars *data_g)
{
	if (data_g->img_fox.ifinsilese == 0)
		return ;
	mlx_destroy_image(data_g->mlx, data_g->img_fox.fox_down[0]);
	mlx_destroy_image(data_g->mlx, data_g->img_fox.fox_down[1]);
	mlx_destroy_image(data_g->mlx, data_g->img_fox.fox_down[2]);
	mlx_destroy_image(data_g->mlx, data_g->img_fox.fox_lefth[0]);
	mlx_destroy_image(data_g->mlx, data_g->img_fox.fox_lefth[1]);
	mlx_destroy_image(data_g->mlx, data_g->img_fox.fox_lefth[2]);
	mlx_destroy_image(data_g->mlx, data_g->img_fox.fox_regth[0]);
	mlx_destroy_image(data_g->mlx, data_g->img_fox.fox_regth[1]);
	mlx_destroy_image(data_g->mlx, data_g->img_fox.fox_regth[2]);
	mlx_destroy_image(data_g->mlx, data_g->img_fox.fox_up[0]);
	mlx_destroy_image(data_g->mlx, data_g->img_fox.fox_up[1]);
	mlx_destroy_image(data_g->mlx, data_g->img_fox.fox_up[2]);
}

void	exit_and_free(void *mlx, void *win, t_vars *data_g)
{
	int	y;

	y = 0;
	while (data_g->g_data[y])
	{
		free(data_g->g_data[y]);
		y++;
	}
	free(data_g->g_data);
	free(data_g->foxes);
	mlx_destroy_image(mlx, data_g->g_map.collectible);
	mlx_destroy_image(mlx, data_g->g_map.empty_space);
	mlx_destroy_image(mlx, data_g->g_map.exit_map_close);
	mlx_destroy_image(mlx, data_g->g_map.exit_map_open);
	mlx_destroy_image(mlx, data_g->g_map.center[0]);
	mlx_destroy_image(mlx, data_g->g_map.center[1]);
	distroy_image_player(data_g);
	distroy_image_foxs(data_g);
	mlx_destroy_image(mlx, data_g->g_map.wall);
	mlx_destroy_window(mlx, win);
	exit(0);
}
