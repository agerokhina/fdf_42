/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:56:27 by aerokhin          #+#    #+#             */
/*   Updated: 2025/01/09 14:17:45 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int32_t	ft_pixel(t_color p)
{
	return (p.r << 24 | p.g << 16 | p.b << 8 | p.a);
}

t_color	interpolate_color(t_color c1, t_color c2, float t)
{
	t_color	result;

	result.r = (int)((1 - t) * c1.r + t * c2.r);
	result.g = (int)((1 - t) * c1.g + t * c2.g);
	result.b = (int)((1 - t) * c1.b + t * c2.b);
	result.a = (int)((1 - t) * c1.a + t * c2.a);
	return (result);
}

t_color	ft_color_from_int(int32_t color)
{
	t_color	result;

	result.r = (color >> 24) & 0xFF;
	result.g = (color >> 16) & 0xFF;
	result.b = (color >> 8) & 0xFF;
	result.a = color & 0xFF;
	return (result);
}
