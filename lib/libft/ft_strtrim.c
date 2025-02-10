/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:22:14 by aerokhin          #+#    #+#             */
/*   Updated: 2024/10/21 12:34:57 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	fl_begin;
	int	fl_end;

	fl_begin = 0;
	fl_end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[fl_begin]))
		fl_begin++;
	while (ft_strchr(set, s1[fl_end]))
		fl_end--;
	return (ft_substr (s1, fl_begin, fl_end - fl_begin + 1));
}
