/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 19:28:36 by aerokhina         #+#    #+#             */
/*   Updated: 2025/01/11 16:20:50 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_return_error(char *err_msg, int system_function)
{
	if (!system_function)
		ft_putendl_fd(err_msg, STDERR_FILENO);
	else
		perror(err_msg);
	exit(EXIT_FAILURE);
}

t_point	ft_point(float x, float y, float z, int color)
{
	t_point	point;

	point.x = y;
	point.y = x;
	point.z = z;
	point.c = color;
	return (point);
}

void	ft_print_arr(t_point **map, t_maps_settings set)
{
	t_pos	p;

	ft_putstr_fd(">>>Entering print_arr \n", 1);
	p.i = 0;
	while (p.i < set.size.height)
	{
		p.j = 0;
		while (p.j < set.size.width)
		{
			ft_printf("%d\t", (int)(map[p.i][p.j++].z * 100));
		}
		ft_printf("\n");
		p.i++;
	}
	ft_putstr_fd(">>>Leaving print_arr \n", 1);
}

void	ft_print_env(t_fdf *env, char *title)
{
	t_maps_settings	set;

	if (env == NULL)
		return ;
	set = env->map_settings;
	ft_printf(">>>	Print_environment: %s\n", title);
	ft_printf(">>>	Map: %p\n>>>	Win: %p\n", env->map, env->win);
	ft_printf(">>>	mlx: %p\n", env->win->mlx);
	ft_printf(">>>	mlx: H: %d W: %d\n", env->win->mlx->height, \
										env->win->mlx->width);
	ft_printf(">>>	image: %p\n", env->win->image);
	ft_printf(">>>	image: H: %d W: %d\n", env->win->image->height, \
										env->win->image->width);
	ft_printf(">>>	Center XxY: %dx%d\n", set.center_x, set.center_y);
	ft_printf(">>>	Map_settings: \n");
	ft_printf(">>>		Scale: %d%%\n", (int)set.scale * 100);
	ft_printf(">>>		Proj: %d\n", set.proj);
	ft_printf(">>>	Z min/max: %d/%d\n", (int)(set.z_min * 100), \
										(int)(set.z_max * 100));
	ft_printf(">>>		Size: H: %d x W: %d\n", set.size.width, \
										set.size.height);
	ft_printf(">>>	Rotation: \n");
	ft_printf(">>>			Alpha: %d\n", (int)(100 * set.rotation.alpha));
	ft_printf(">>>			Beta: %d\n", (int)(100 * set.rotation.beta));
	ft_printf(">>>			Gamma: %d\n", (int)(100 * set.rotation.gamma));
}

void	ft_print_color(char *title, t_color color)
{
	ft_printf(">	C%s: (%d, %d, %d, %d)\n", \
		title, color.r, color.g, color.b, color.a);
}
