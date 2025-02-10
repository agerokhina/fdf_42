/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:43:45 by aerokhin          #+#    #+#             */
/*   Updated: 2024/12/30 17:15:43 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_copy_values(char **str, int i, int *is)
{
	char	*line;
	char	*temp;

	line = ft_substr(*str, 0, i + 1);
	if (!line)
	{
		*is = 0;
		return (ft_free(str));
	}
	temp = ft_substr(*str, i + 1, ft_strlen(*str) - i + 1);
	if (!temp)
		return (ft_free_all(str, &line, is));
	ft_free(str);
	*str = temp;
	return (line);
}

char	*ft_free(char **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (NULL);
}

char	*ft_free_all(char **ptr1, char **ptr2, int *ptr4)
{
	if (*ptr1 != NULL)
	{
		free(*ptr1);
		*ptr1 = NULL;
	}
	if (*ptr2 != NULL)
	{
		free(*ptr2);
		*ptr2 = NULL;
	}
	*ptr4 = 0;
	return (NULL);
}

char	*my_read_fd(int fd, const char *str)
{
	char		*buffer;
	int			read_buffer;
	char		*temp;
	char		*res;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_buffer = BUFFER_SIZE;
	res = ft_strjoin(str, "");
	if (!res)
		return (ft_free(&buffer));
	while (ft_findchr(res, '\n') == -1 && read_buffer == BUFFER_SIZE)
	{
		read_buffer = read(fd, buffer, BUFFER_SIZE);
		if (read_buffer == -1)
			return (ft_free (&res), ft_free (&buffer), NULL);
		buffer [read_buffer] = '\0';
		temp = ft_strjoin (res, buffer);
		if (!temp)
			return (ft_free (&res), ft_free (&buffer), NULL);
		ft_free(&res);
		res = temp;
	}
	return (ft_free (&buffer), res);
}

char	*gnl(int fd)
{
	static char	*str;
	char		*temp;
	ssize_t		pos;
	static int	is_initialized;

	if (ft_start_checks(&str, &is_initialized, fd) == NULL)
		return (NULL);
	if (ft_findchr(str, '\n') == -1)
	{
		if (!str)
			return (is_initialized = 0, NULL);
		temp = my_read_fd(fd, str);
		if (!temp || *temp == 0)
			return (ft_free_all(&str, &temp, &is_initialized));
		ft_free(&str);
		str = temp;
	}
	if (!str)
		return (is_initialized = 0, NULL);
	pos = ft_findchr(str, '\n');
	if (pos == -1)
		return (is_initialized = -1, str);
	return (ft_copy_values (&str, pos, &is_initialized));
}
