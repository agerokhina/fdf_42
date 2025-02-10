/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:23:32 by aerokhin          #+#    #+#             */
/*   Updated: 2024/10/21 12:33:40 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nu;
	char			symbols[12];
	int				i;

	nu = -(unsigned int) n * (n < 0) + n * (n >= 0);
	i = 0;
	if (n == 0)
		ft_putchar_fd('0', fd);
	else
	{
		while (nu > 0)
		{
			symbols[i] = nu % 10 + '0';
			nu = nu / 10;
			i++;
		}
		i--;
		if (n < 0)
			ft_putchar_fd('-', fd);
		while (i >= 0)
		{
			ft_putchar_fd(symbols[i], fd);
			i--;
		}
	}
}
