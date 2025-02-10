/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:28:10 by aerokhin          #+#    #+#             */
/*   Updated: 2024/10/14 16:13:10 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*t;
	char	chr;

	t = NULL;
	chr = (char)c;
	while (*s != '\0')
	{
		if (*s == chr)
			t = (char *)s;
		s++;
	}
	if (chr == 0)
		return ((char *)s);
	else
		return ((char *)t);
}
