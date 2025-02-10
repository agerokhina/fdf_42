/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:22:14 by aerokhin          #+#    #+#             */
/*   Updated: 2024/10/21 12:33:05 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	my_intlen(int n)
{
	size_t			len;
	unsigned int	nl;

	nl = (unsigned int)n;
	len = 0;
	while (nl > 0)
	{
		len++;
		nl = nl / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int				sign;
	unsigned int	nl;
	char			*res;
	size_t			len;

	nl = -(unsigned int) n * (n < 0) + n * (n >= 0);
	if (n == 0)
		return (ft_strdup("0"));
	sign = 0;
	if (n < 0)
		sign = 1;
	len = my_intlen(nl);
	res = (char *)malloc(len + sign + 1);
	if (!res)
		return (NULL);
	res[len + sign] = 0;
	while (nl > 0)
	{
		res[len + sign - 1] = nl % 10 + '0';
		nl = nl / 10;
		len--;
	}
	if (sign)
		res[0] = '-';
	return (res);
}

// int main(void)
// {
// 	char *c = ft_itoa(-2147483648);
// 	printf("'%s'", c);
// 	free(c);
// }