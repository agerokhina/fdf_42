/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:27:18 by aerokhin          #+#    #+#             */
/*   Updated: 2024/11/08 17:21:03 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*my_case(char c, va_list args, ssize_t *s_len)
{
	char	*t;

	*s_len = 0;
	if (c == '%')
		return (*s_len = 1, ft_strdup("%"));
	if (c == 'c')
		return (my_sub_c((char)va_arg(args, int), s_len));
	if (c == 's')
	{
		t = (char *)va_arg(args, char *);
		if (!t)
			return (*s_len = 6, ft_strdup("(null)"));
		else
			return (*s_len = ft_strlen(t), ft_strdup(t));
	}
	if (c == 'p')
		return (my_sub_p((uintptr_t)va_arg(args, uintptr_t), s_len));
	if (c == 'd' || c == 'i')
	{
		t = ft_itoa((int)va_arg(args, int));
		return (*s_len = ft_strlen(t), t);
	}
	if ((c == 'u') || (c == 'x') || (c == 'X'))
		return (my_sub_h_d((unsigned int)va_arg(args, unsigned int), c, s_len));
	return (ft_strdup(""));
}

int	ft_printf(const char *s, ...)
{
	char	*t;
	va_list	args;
	ssize_t	total_len;
	ssize_t	check_res;

	if (s == NULL)
		return (-1);
	va_start(args, s);
	total_len = 0;
	t = parse(s, args, &total_len);
	if (t == NULL)
	{
		va_end(args);
		return (-1);
	}
	check_res = write(1, t, total_len);
	free(t);
	va_end(args);
	if (check_res == -1)
		return (-1);
	else
		return (total_len);
}
