/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:25:06 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/12/06 09:30:13 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	size_s1;

	size_s1 = (ft_strlen(s1) + 1);
	str = (char *)malloc(sizeof(char) * size_s1);
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1, size_s1);
	return (str);
}
