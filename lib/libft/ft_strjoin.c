/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:44:55 by aerokhin          #+#    #+#             */
/*   Updated: 2024/10/21 17:00:35 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	if (__SIZE_MAX__ - ft_strlen(s1) < ft_strlen(s2))
		return (NULL);
	dest = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[i - ft_strlen(s1)])
	{
		dest[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
