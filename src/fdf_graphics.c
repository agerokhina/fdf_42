/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_graphics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:33:48 by aerokhin          #+#    #+#             */
/*   Updated: 2025/01/09 14:18:46 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static t_line	ft_line_init(t_pixel x1, t_pixel x2)
{
	t_line	line;

	line.dx = abs(x2.x - x1.x) * 1;
	line.sx = (x1.x < x2.x) - (x1.x >= x2.x);
	line.dy = -abs(x2.y - x1.y) * 1;
	line.sy = (x1.y < x2.y) - (x1.y >= x2.y);
	line.err = line.dx + line.dy;
	return (line);
}

void	ft_drawline(mlx_image_t *img, \
					t_pixel x1, t_pixel x2, t_maps_settings map)
{
	t_line	line;
	float	steps;
	float	t;
	t_color	color;

	line = ft_line_init(x1, x2);
	steps = fmax(abs(x2.x - x1.x), abs(x2.y - x1.y));
	while (1)
	{
		t = sqrt(pow(x1.x - x2.x, 2) + pow(x1.y - x2.y, 2)) / steps;
		color = interpolate_color(x2.c, x1.c, t);
		if (x1.x >= 0 && x1.x < map.win_width && \
			x1.y >= 0 && x1.y < map.win_height)
			mlx_put_pixel(img, (int)x1.x, (int)x1.y, ft_pixel(color));
		if (x1.x == x2.x && x1.y == x2.y)
			break ;
		line.e2 = 2 * line.err;
		if (line.e2 >= line.dy || line.e2 <= line.dx)
		{
			line.err += (line.dy * (line.e2 >= line.dy) + \
						line.dx * (line.e2 <= line.dx));
			x1.x += line.sx * (line.e2 >= line.dy);
			x1.y += line.sy * (line.e2 <= line.dx);
		}
	}
}

void	ft_put_line(mlx_image_t *image, t_point p1, \
					t_point p2, t_maps_settings map)
{
	t_pixel		px1;
	t_pixel		px2;

	if (map.proj == DIMETRIC)
	{
		px1 = dimetric_projection(p1, map.scale, map.rotation);
		px2 = dimetric_projection(p2, map.scale, map.rotation);
	}
	else if (map.proj == ISOMETRIC)
	{
		px1 = isometric_projection(p1, map.scale, map.rotation);
		px2 = isometric_projection(p2, map.scale, map.rotation);
	}
	else
	{
		px1 = top_projection(p1, map.scale);
		px2 = top_projection(p2, map.scale);
	}
	px1.x += map.center_x;
	px1.y += map.center_y;
	px2.x += map.center_x;
	px2.y += map.center_y;
	px1.c = ft_color_from_int(p1.c);
	px2.c = ft_color_from_int(p2.c);
	ft_drawline(image, px1, px2, map);
}

void	ft_draw_map(mlx_image_t *image, t_fdf **env)
{
	t_pos	pos;
	t_point	p11;
	t_point	p12;
	t_point	p21;

	pos.i = -1;
	while (++pos.i < (*env)->map_settings.size.height -1)
	{
		pos.j = -1;
		while (++pos.j < (*env)->map_settings.size.width - 1)
		{
			p11 = ft_scale_coord((*env)->map[pos.i][pos.j]);
			p12 = ft_scale_coord((*env)->map[pos.i][pos.j + 1]);
			p21 = ft_scale_coord((*env)->map[pos.i + 1][pos.j]);
			ft_put_line(image, p11, p12, (*env)->map_settings);
			ft_put_line(image, p11, p21, (*env)->map_settings);
		}
		p11 = ft_scale_coord(\
			(*env)->map[pos.i][(*env)->map_settings.size.width - 1]);
		p12 = ft_scale_coord(\
			(*env)->map[pos.i + 1][(*env)->map_settings.size.width - 1]);
		ft_put_line(image, p11, p12, (*env)->map_settings);
	}
	ft_last_line(image, &(*env));
}

void	ft_last_line(mlx_image_t *image, t_fdf **env)
{
	t_pos	pos;
	t_point	p11;
	t_point	p12;

	pos.i = (*env)->map_settings.size.height - 1;
	pos.j = -1;
	while (++pos.j < (*env)->map_settings.size.width - 1)
	{
		p11 = ft_scale_coord((*env)->map[pos.i][pos.j]);
		p12 = ft_scale_coord((*env)->map[pos.i][pos.j + 1]);
		ft_put_line(image, p11, p12, (*env)->map_settings);
	}
}
