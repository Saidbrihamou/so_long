/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:40:42 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/12/08 15:52:05 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

static long	countsize(long i)
{
	long	div;

	div = 1;
	while (1)
	{
		if (i >= div && i < div * 10)
		{
			return (div);
		}
		div *= 10;
	}
	return (1);
}

static void	inttochar(char *str, long div, long n, int *index)
{
	while (div > 0)
	{
		str[*index] = n / div + '0';
		n -= (n / div) * div;
		div /= 10;
		(*index)++;
	}
}

static size_t	countlen(long n)
{
	size_t	size;
	long	div;

	if (n == 0)
		return (2);
	size = 2;
	if (n < 0)
	{
		n *= -1;
		size++;
	}
	div = 1;
	while (1)
	{
		if (n >= div && n < div * 10)
		{
			break ;
		}
		div *= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long	new_n;
	char	*res;
	int		index;

	index = 0;
	new_n = n;
	res = (char *)malloc(countlen(new_n) * sizeof(char));
	if (!res)
		return (NULL);
	if (new_n < 0)
	{
		new_n *= -1;
		res[index++] = '-';
	}
	if (new_n == 0)
		res[index++] = '0';
	else
		inttochar(res, countsize(new_n), new_n, &index);
	res[index] = '\0';
	return (res);
}
