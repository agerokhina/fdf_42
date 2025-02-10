/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:23:03 by aerokhin          #+#    #+#             */
/*   Updated: 2025/01/09 13:24:14 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_close_window(void *param)
{
	t_fdf	**env;

	env = (t_fdf **)param;
	ft_free_env(&(*env));
	*env = NULL;
	exit(0);
}

void	ft_hook_reactions(t_fdf **env, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_Q || keydata.key == MLX_KEY_W)
		(*env)->map_settings.rotation.alpha += \
			0.1 * ((keydata.key == MLX_KEY_W) - (keydata.key == MLX_KEY_Q));
	if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_S)
		(*env)->map_settings.rotation.beta += \
			0.1 * ((keydata.key == MLX_KEY_S) - (keydata.key == MLX_KEY_A));
	if (keydata.key == MLX_KEY_Z || keydata.key == MLX_KEY_X)
		(*env)->map_settings.rotation.gamma += \
			0.1 * ((keydata.key == MLX_KEY_X) - (keydata.key == MLX_KEY_Z));
	if (keydata.key == MLX_KEY_KP_ADD || keydata.key == MLX_KEY_EQUAL)
		(*env)->map_settings.scale += 0.1;
	if (keydata.key == MLX_KEY_KP_SUBTRACT || keydata.key == MLX_KEY_MINUS)
		(*env)->map_settings.scale -= 0.1 * ((*env)->map_settings.scale > 0.1);
	if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_DOWN)
		(*env)->map_settings.center_y -= \
			10 * ((keydata.key == MLX_KEY_UP) - (keydata.key == MLX_KEY_DOWN));
	if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT)
		(*env)->map_settings.center_x += \
		10 * ((keydata.key == MLX_KEY_RIGHT) - (keydata.key == MLX_KEY_LEFT));
	if (keydata.key == MLX_KEY_SPACE)
		ft_init_mapsettintgs(&(*env)->map_settings);
	if (keydata.key == MLX_KEY_ENTER && keydata.action == MLX_RELEASE)
		(*env)->map_settings.proj = ((*env)->map_settings.proj + 1) % 3;
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_fdf	**env;

	env = (t_fdf **)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
	{
		ft_close_window(param);
		return ;
	}
	ft_hook_reactions(&(*env), keydata);
	if ((*env)->win->mlx && (*env)->win->image)
	{
		mlx_delete_image((*env)->win->mlx, (*env)->win->image);
		(*env)->win->image = mlx_new_image((*env)->win->mlx, \
					(*env)->win->mlx->width, (*env)->win->mlx->height);
		if (!(*env)->win->image)
			exit(1);
		mlx_image_to_window((*env)->win->mlx, (*env)->win->image, 0, 0);
		ft_draw_map((*env)->win->image, &(*env));
	}
}

void	handle_resize(int32_t width, int32_t height, void *param)
{
	mlx_t	*mlx;
	t_fdf	**env;

	env = (t_fdf **)param;
	if ((*env) && (*env)->win && (*env)->win->mlx)
	{
		mlx = (*env)->win->mlx;
		if ((*env)->win->image)
		{
			mlx_delete_image(mlx, (*env)->win->image);
		}
		(*env)->win->image = mlx_new_image(mlx, width, height);
		if (!(*env)->win->image)
		{
			perror("mlx_new_image failed");
			exit(1);
		}
		mlx_image_to_window(mlx, (*env)->win->image, 0, 0);
		(*env)->map_settings.win_width = width;
		(*env)->map_settings.win_height = height;
		ft_draw_map((*env)->win->image, env);
	}
}
