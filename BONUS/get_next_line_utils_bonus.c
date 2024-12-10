/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:59:32 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/12/06 09:30:25 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

char	*ft_strjoin_and_free(const char *buffer, ssize_t	len_buffer, \
										char *temp, size_t *num_line_read)
{
	size_t	len_temp;
	char	*result;
	ssize_t	i;

	i = 0;
	len_temp = 0;
	while (temp != NULL && temp[len_temp])
		len_temp++;
	while (i < len_buffer)
	{
		if (buffer[i++] == '\n')
			(*num_line_read)++;
	}
	result = malloc(sizeof(char) * (len_temp + len_buffer + 1));
	if (result == NULL)
		return (NULL);
	result[0] = '\0';
	ft_cat(result, temp, len_temp);
	ft_cat(result, buffer, len_buffer);
	free(temp);
	return (result);
}

char	*create_result(char *temp, char *buffer_static[10250], \
													ssize_t num_read, int fd)
{
	size_t	size_temp;
	size_t	index;
	char	*result;

	if (num_read == -1)
	{
		buffer_static[fd][0] = '\0';
		return (NULL);
	}
	index = 0;
	if (temp != NULL)
		while (temp[index] && temp[index] != '\n')
			index++;
	size_temp = index + 1;
	index = 0;
	while (buffer_static[fd][index] && buffer_static[fd][index] != '\n')
		index++;
	result = malloc(sizeof(char) * (size_temp + index + 2));
	if (result == NULL)
		return (NULL);
	result[0] = '\0';
	ft_cat(result, buffer_static[fd], index + 1);
	ft_cat(result, temp, size_temp);
	ft_update_rest_and_temp(temp, buffer_static, fd);
	return (result);
}

void	ft_update_rest_and_temp(char *temp, \
						char *buffer_static[10250], int fd)
{
	size_t	index;
	size_t	i_rest;

	index = 0;
	i_rest = 0;
	if (temp != NULL)
	{
		while (temp[index] && temp[index] != '\n')
			index++;
		while (temp[index] && temp[index + 1])
			buffer_static[fd][i_rest++] = temp[index++ + 1];
		buffer_static[fd][i_rest] = '\0';
	}
	else
	{
		while (buffer_static[fd][index] && buffer_static[fd][index] != '\n')
			index++;
		while (buffer_static[fd][index] && buffer_static[fd][index + 1])
			buffer_static[fd][i_rest++] = buffer_static[fd][index++ + 1];
		buffer_static[fd][i_rest] = '\0';
	}
	if (buffer_static[fd][0] == '\0')
		my_free(&buffer_static[fd]);
	free(temp);
}

size_t	count_newline(char *str[10250], int fd)
{
	size_t	num_newline;
	size_t	i;

	num_newline = 0;
	i = 0;
	if (!str || fd < 0 || fd >= 10250)
		return (0);
	while (str[fd][i])
	{
		if (str[fd][i] == '\n')
			num_newline++;
		i++;
	}
	return (num_newline);
}

void	ft_cat(char *dst, const char *src, size_t len_src)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!dst || !src)
		return ;
	while (dst[i])
		i++;
	while (j < len_src)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
}
