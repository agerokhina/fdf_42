/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_prints.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:52:11 by aerokhin          #+#    #+#             */
/*   Updated: 2024/11/05 17:05:30 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*my_sub_c(int c, ssize_t *res_len)
{
	char	*r;

	r = (char *)malloc(sizeof(char) * 2);
	if (!r)
		return (NULL);
	r[0] = (char)c;
	r[1] = 0;
	*res_len = 1;
	return (r);
}

char	*my_sub_p(uintptr_t address, ssize_t *res_len)
{
	char	*addr;
	char	*res;
	char	*base;
	ssize_t	len;

	if (address == 0)
		return (*res_len = 5, ft_strdup("(nil)"));
	base = "0123456789abcdef";
	len = my_address_len(address);
	*res_len = len + 2;
	addr = (char *)ft_calloc(len + 1, sizeof(char));
	if (!addr)
		return (NULL);
	while (len > 0)
	{
		addr[len - 1] = base[address % 16];
		address = address / 16;
		len--;
	}
	res = ft_strjoin("0x", addr);
	free (addr);
	return (res);
}

char	*my_sub_h_d(unsigned int nbr, char c, ssize_t *res_len)
{
	char			*res;
	ssize_t			len;
	char			*base;
	int				bas;

	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789";
	bas = ft_strlen(base);
	len = my_number_len(nbr, bas);
	*res_len = len;
	res = (char *)ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	while (len > 0)
	{
		res[len - 1] = base[nbr % bas];
		nbr = nbr / bas;
		len--;
	}
	return (res);
}

ssize_t	my_number_len(unsigned int nbr, int bas)
{
	ssize_t	len;

	if (nbr == 0)
		return (1);
	len = 0;
	while (nbr > 0)
	{
		len++;
		nbr = nbr / bas;
	}
	return (len);
}

ssize_t	my_address_len(uintptr_t nbr)
{
	ssize_t	len;

	if (nbr == 0)
		return (1);
	len = 0;
	while (nbr > 0)
	{
		len++;
		nbr = nbr / 16;
	}
	return (len);
}
