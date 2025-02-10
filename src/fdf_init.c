/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:03:19 by aerokhin          #+#    #+#             */
/*   Updated: 2025/01/09 15:51:07 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_init_mapsettintgs(t_maps_settings *map_settings)
{
	map_settings->rotation.alpha = 0;
	map_settings->rotation.beta = 0;
	map_settings->rotation.gamma = 0;
	map_settings->scale = 1;
	map_settings->proj = ISOMETRIC;
	map_settings->center_x = map_settings->win_width / 2;
	map_settings->center_y = map_settings->win_height / 2;
}

void	ft_init_env(char *filename, t_fdf **env)
{
	int	fd;

	fd = ft_fdinit(filename);
	*env = malloc(sizeof(t_fdf));
	if (!*env)
		ft_return_error("Failed to allocate memory for *environment", 0);
	(*env)->map_settings.size.height = ft_get_height(filename);
	(*env)->map_settings.size.width = ft_get_width(filename);
	(*env)->map = ft_arrread(fd, (*env)->map_settings.size);
	if (!(*env)->map)
		ft_return_error("Error: failed to read map", 0);
	(*env)->map_settings.win_width = WIDTH;
	(*env)->map_settings.win_height = HEIGHT;
	ft_init_mapsettintgs(&(*env)->map_settings);
	ft_find_z_min_max(env);
	ft_refill_color(env);
	(*env)->win = malloc(sizeof(t_mlx_windows));
	if (!(*env)->win)
		ft_return_error("Failed to allocate memory for window", 0);
	(*env)->win->mlx = mlx_init(WIDTH, HEIGHT, filename, true);
	if (!(*env)->win->mlx)
		ft_return_error("Failed to initialize mlx", 0);
	(*env)->win->image = mlx_new_image((*env)->win->mlx, WIDTH, HEIGHT);
	if (!(*env)->win->image)
		ft_return_error("Failed to create image", 0);
}

void	ft_init(char *filename, t_fdf **env)
{
	if (!filename)
		ft_return_error("Error: invalid filename", 0);
	ft_init_env(filename, env);
	if (!(*env))
		ft_return_error("Error: failed to allocate memory for env", 0);
}
