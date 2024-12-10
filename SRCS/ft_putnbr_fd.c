/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:38:53 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/12/05 16:45:48 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	i;
	char	c;

	i = n;
	if (fd < 0)
		return ;
	if (i < 0)
	{
		i *= -1;
		write(fd, "-", 1);
	}
	if (i > 9)
	{
		ft_putnbr_fd(i / 10, fd);
	}
	c = i % 10 + '0';
	write(fd, &c, 1);
}
