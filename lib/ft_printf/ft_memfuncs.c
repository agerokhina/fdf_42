/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memfuncs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:44:55 by aerokhin          #+#    #+#             */
/*   Updated: 2024/11/05 16:52:23 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdlib.h>

char	*ft_memdup(const char *src, ssize_t len)
{
	char	*dest;
	ssize_t	i;

	i = 0;
	dest = (char *)malloc(len + 1);
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_memjoin(char const *s1, ssize_t len1, char const *s2, ssize_t len2)
{
	char	*dest;
	ssize_t	i;

	if (!s1 && !s2)
		return (NULL);
	if ((ssize_t)((__SIZE_MAX__ / 2)) - len1 < len2)
		return (NULL);
	dest = (char *)ft_calloc(len1 + len2 + 1, sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		dest[i] = s1[i];
		i++;
	}
	while (i - len1 < len2)
	{
		dest[i] = s2[i - len1];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
