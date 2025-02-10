/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helping.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:52:11 by aerokhin          #+#    #+#             */
/*   Updated: 2024/11/05 16:34:38 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*my_substring(const char *s, ssize_t	*subs_len)
{
	ssize_t	i;

	i = 0;
	while (s[i] != '%' && s[i] != 0)
		i++;
	*subs_len = i;
	return (ft_substr(s, 0, i));
}

ssize_t	my_copysubstr(char **res, char c, va_list args, ssize_t *total_len)
{
	char	*temp;
	char	*t;
	int		fl;
	ssize_t	case_len;

	fl = ft_strchr("cspdiuxX%", c) != 0;
	if (fl && c != 0)
	{
		t = my_case(c, args, &case_len);
		if (!t)
			return (-1);
		temp = ft_memjoin(*res, *total_len, t, case_len);
		free(t);
	}
	else if (c == 0)
		temp = ft_memjoin(*res, *total_len, "", 0);
	else
		temp = ft_memjoin(*res, *total_len, "%", 1);
	if (!temp)
		return (-1);
	free(*res);
	*res = temp;
	*total_len += (fl && c != 0) * case_len + (!fl && c != 0);
	return ((fl && c != 0) * 2 + (!fl || c == 0));
}

ssize_t	my_combine(char **res, const char *s, ssize_t l, ssize_t *total_len)
{
	char	*temp;
	char	*substr;
	ssize_t	len_subs;

	substr = my_substring(s + l, &len_subs);
	if (!substr)
		return (-1);
	temp = ft_memjoin(*res, *total_len, substr, len_subs);
	free(substr);
	if (!temp)
		return (-1);
	free (*res);
	*res = temp;
	*total_len += len_subs;
	return (len_subs);
}

char	*parse(const char *s, va_list args, ssize_t *total_len)
{
	ssize_t	pos;
	ssize_t	temp;
	char	*res;

	res = my_substring(s, total_len);
	if (!res)
		return (NULL);
	pos = (ssize_t)(*total_len);
	while (s[pos] != 0 && pos < (ssize_t)ft_strlen(s))
	{
		if (s[pos] == '%')
		{
			temp = my_copysubstr(&res, s[pos + 1], args, total_len);
			if (temp == -1)
				return (NULL);
			pos += (size_t)temp;
			temp = my_combine(&res, s, pos, total_len);
			if (temp == -1)
				return (NULL);
			pos = (size_t)temp + pos;
		}
	}
	return (res);
}
