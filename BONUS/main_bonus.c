/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:01:58 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/12/09 13:06:52 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

int	closewindo(void *mlx_and_win[3])
{
	exit_and_free(mlx_and_win[0], mlx_and_win[1], mlx_and_win[2]);
	return (0);
}

void	insialse_mlx_and_data_g(t_vars	*data_g, void **mlx, void **win)
{
	*mlx = mlx_init();
	*win = mlx_new_window(*mlx, S_PX * data_g->size.x, \
					S_PX * data_g->size.y, "SO_LONG");
	data_g->mlx = *mlx;
	data_g->win = *win;
	data_g->game_over = 0;
	count_total_carrot(data_g);
	data_g->g_count_move = 0;
}

int	main(int argC, char **argV)
{
	void	*mlx;
	void	*win;
	void	*mlx_and_win_data[3];
	t_vars	data_g;

	if (argC != 2)
	{
		ft_putstr_fd("Error\nPlease get file is in .ber format", 2);
		exit(0);
	}
	main_cheak(argV[1], &data_g);
	insialse_mlx_and_data_g(&data_g, &mlx, &win);
	mlx_and_win_data[0] = mlx;
	mlx_and_win_data[1] = win;
	mlx_and_win_data[2] = &data_g;
	set_map(mlx_and_win_data, data_g.size, &data_g);
	data_g.g_pos_door = get_me_pos_player_ordoor('E', &data_g);
	mlx_hook(win, 17, 0, closewindo, mlx_and_win_data);
	mlx_loop_hook(mlx, updata_move, &data_g);
	mlx_key_hook(win, handle_key, mlx_and_win_data);
	mlx_loop(mlx);
	return (0);
}
