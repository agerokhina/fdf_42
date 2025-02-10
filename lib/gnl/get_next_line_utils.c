/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:21:22 by aerokhin          #+#    #+#             */
/*   Updated: 2024/11/14 18:19:26 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_findchr(const char *s, int c)
{
	unsigned char	chr;
	ssize_t			i;
	ssize_t			len;

	if (s == NULL)
		return (-1);
	if (s[0] == '\0')
		return (-1);
	len = ft_strlen(s);
	i = 0;
	chr = (unsigned char)c;
	while (i < len && s[i] != chr)
		i++;
	if (s[i] == chr)
		return (i);
	else
		return (-1);
}

ssize_t	ft_strlen(const char *str)
{
	ssize_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	ssize_t	i;
	ssize_t	len1;
	ssize_t	len2;

	if ((!s1 || !s2))
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dest = malloc((len1 + len2 + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[i - len1])
	{
		dest[i] = s2[i - len1];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, ssize_t len)
{
	char	*dest;
	ssize_t	str_len;
	ssize_t	i;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		len = 0;
	else if (start + len > str_len)
		len = str_len - start;
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)s)[i + start];
		i++;
	}
	dest[len] = '\0';
	return (dest);
}

char	*ft_start_checks(char **str, int *is_initialized, int fd)
{
	if (fd == -1 || BUFFER_SIZE < 0)
	{
		return (NULL);
	}
	if (*is_initialized == 0)
	{
		*str = ft_strjoin("", "");
		if (!*str)
			return (NULL);
	}
	if (*is_initialized == -1)
	{
		*is_initialized = 0;
		return (NULL);
	}
	*is_initialized = 1;
	return (*str);
}
