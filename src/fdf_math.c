/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:13:02 by aerokhin          #+#    #+#             */
/*   Updated: 2025/01/06 14:53:14 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	rotate_point(t_point *point, t_rotation angles)
{
	float	original_x;
	float	original_y;
	float	original_z;

	original_x = point->x;
	original_y = point->y;
	original_z = point->z;
	point->y = original_y * cos(angles.alpha) - original_z * sin(angles.alpha);
	point->z = original_y * sin(angles.alpha) + original_z * cos(angles.alpha);
	original_y = point->y;
	original_z = point->z;
	point->x = original_x * cos(angles.beta) + original_z * sin(angles.beta);
	point->z = -original_x * sin(angles.beta) + original_z * cos(angles.beta);
	original_x = point->x;
	original_z = point->z;
	point->x = original_x * cos(angles.gamma) - original_y * sin(angles.gamma);
	point->y = original_x * sin(angles.gamma) + original_y * cos(angles.gamma);
}

int	ft_atoi_base(char *str, char *basestr)
{
	int32_t	length;
	int32_t	pos;
	int32_t	positive;
	int32_t	nb;
	int32_t	base;

	length = ft_strlen((char *)str);
	base = ft_strlen(basestr);
	positive = 1;
	pos = 0;
	nb = 0;
	if (str[0] == '-')
	{
		positive = -1;
		pos++;
	}
	while (pos < length)
		nb = (nb * base + (ft_findchr(basestr, ft_tolower(str[pos++]))));
	return (nb * positive);
}

t_point	ft_scale_coord(t_point point)
{
	point.x = (point.x) * MAPS_SCALE;
	point.y = (point.y) * MAPS_SCALE;
	point.z = (point.z) * MAPS_SCALE;
	return (point);
}
