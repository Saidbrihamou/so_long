/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer_print_error_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:18:47 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/12/08 21:22:10 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	exit_with_error(char *msg, t_pos size, t_vars *data_g)
{
	int	y;

	y = 0;
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	while (y < size.y && size.y != 0)
	{
		free(data_g->g_data[y]);
		y++;
	}
	free(data_g->g_data);
	exit(1);
}

t_var_cheak	inisialyse(void)
{
	t_var_cheak	all_var;

	all_var.n_exit = 0;
	all_var.n_start = 0;
	all_var.n_carrot = 0;
	all_var.y = 0;
	all_var.x = 0;
	return (all_var);
}
