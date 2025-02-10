/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_maps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:17:58 by aerokhin          #+#    #+#             */
/*   Updated: 2025/01/09 18:00:53 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_point	ft_dec(char *str, int base)
{
	t_point	point;
	char	**split;
	char	*basestr;

	if (base == 10)
		basestr = "0123456789";
	else
		basestr = "0123456789abcdef";
	split = ft_split(str, ',');
	point.z = ft_atoi(split[0]);
	if (split[1] != NULL)
		point.c = ft_atoi_base(split[1] + 2, basestr) * 256 + 255;
	else
		point.c = -1;
	if (split[1] != NULL)
		ft_free(&split[1]);
	ft_free(&split[0]);
	ft_free((char **)&split);
	return (point);
}

void	ft_find_z_min_max(t_fdf **env)
{
	t_pos	p;

	p.i = 0;
	(*env)->map_settings.z_min = (*env)->map[0][0].z;
	(*env)->map_settings.z_max = (*env)->map[0][0].z;
	while (p.i < (*env)->map_settings.size.height)
	{
		p.j = 0;
		while (p.j < (*env)->map_settings.size.width)
		{
			if ((*env)->map[p.i][p.j].z < (*env)->map_settings.z_min)
				(*env)->map_settings.z_min = (*env)->map[p.i][p.j].z;
			if ((*env)->map[p.i][p.j].z > (*env)->map_settings.z_max)
				(*env)->map_settings.z_max = (*env)->map[p.i][p.j].z;
			p.j++;
		}
		p.i++;
	}
}

void	ft_refill_color(t_fdf **env)
{
	t_pos	p;
	float	t;

	p.i = 0;
	while (p.i < (*env)->map_settings.size.height)
	{
		p.j = 0;
		while (p.j < (*env)->map_settings.size.width)
		{
			if ((*env)->map_settings.z_min == (*env)->map_settings.z_max)
				t = 0;
			else
				t = ((*env)->map[p.i][p.j].z - (*env)->map_settings.z_min) / \
					((*env)->map_settings.z_max - (*env)->map_settings.z_min);
			if ((*env)->map[p.i][p.j].c == -1)
				(*env)->map[p.i][p.j].c = ft_pixel(interpolate_color(\
									ft_color_from_int(GRADIENT_MIN), \
									ft_color_from_int(GRADIENT_MAX), t));
			p.j++;
		}
		p.i++;
	}
}
