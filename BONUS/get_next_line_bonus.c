/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:59:41 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/12/06 09:30:22 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

int	ft_allocat(char **buffer)
{
	if (*buffer != NULL)
		return (1);
	if (BUFFER_SIZE > INT_MAX || BUFFER_SIZE <= 0)
		return (0);
	*buffer = malloc(BUFFER_SIZE * sizeof(char));
	if (!buffer)
		return (0);
	buffer[0][0] = '\0';
	return (1);
}

int	my_free(char **p)
{
	free(*p);
	*p = NULL;
	return (1);
}

int	check_isnothing_and_free(char **buffer, char *temp, \
										char *buffer_static[10250], int fd)
{
	return (my_free(buffer) && temp == NULL && buffer_static[fd][0] == '\0' \
											&& my_free(&buffer_static[fd]));
}

int	check_buffsize_fd_and_allocat(int fd, char *buffer_static[10250], \
															char **buffer)
{
	return ((fd < 0 || fd >= 10250) || !ft_allocat(&buffer_static[fd]) \
													|| !ft_allocat(buffer));
}

char	*get_next_line(int fd)
{
	static char		*buffer_static[10250] = {NULL};
	size_t			num_line_read;
	ssize_t			num_read;
	char			*buffer;
	char			*temp;

	temp = NULL;
	buffer = NULL;
	if (check_buffsize_fd_and_allocat(fd, buffer_static, &buffer))
		return (NULL);
	num_line_read = count_newline(buffer_static, fd);
	while (1)
	{
		if (num_line_read > 0)
			break ;
		num_read = read(fd, buffer, BUFFER_SIZE);
		if (num_read == 0 || num_read == -1)
			break ;
		temp = ft_strjoin_and_free(buffer, num_read, temp, &num_line_read);
		if (temp == NULL && my_free(&buffer))
			return (NULL);
	}
	if (check_isnothing_and_free(&buffer, temp, buffer_static, fd))
		return (NULL);
	return (create_result(temp, buffer_static, num_read, fd));
}
