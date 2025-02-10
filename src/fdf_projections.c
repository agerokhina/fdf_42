/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:53:16 by aerokhin          #+#    #+#             */
/*   Updated: 2025/01/06 15:15:06 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

//isometric_projection
t_pixel	isometric_projection(t_point point, float scale, t_rotation rotation)
{
	t_pixel	projected;

	rotate_point(&point, rotation);
	projected.x = (int)((point.x - point.y) * cos(M_PI / 6) * scale);
	projected.y = (int)(((point.x + point.y) * \
							sin(M_PI / 6) - point.z) * scale);
	projected.c = ft_color_from_int(point.c);
	return (projected);
}

//dimetric_projection
t_pixel	dimetric_projection(t_point point, float scale, t_rotation rotation)
{
	t_pixel	projected;
	float	sqrt2;
	float	sqrt6;

	sqrt2 = sqrt(2);
	sqrt6 = sqrt(6);
	rotate_point(&point, rotation);
	projected.x = (int)(((sqrt2 / 2) * point.x + \
					(sqrt2 / 2) * point.z) * scale);
	projected.y = (int)(((-1 / sqrt6) * point.x + \
					(2 / sqrt6) * point.y + (-1 / sqrt6) * point.z) * scale);
	projected.c = ft_color_from_int(point.c);
	return (projected);
}

t_pixel	top_projection(t_point point, float scale)
{
	t_pixel	projected;

	projected.x = (int)(point.x * scale);
	projected.y = (int)(point.y * scale);
	projected.c = ft_color_from_int(point.c);
	return (projected);
}
