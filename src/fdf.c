/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:45:58 by aerokhin          #+#    #+#             */
/*   Updated: 2025/01/07 17:23:56 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	main(int argc, char *argv[])
{
	t_fdf	**env;

	if (argc == 2)
	{
		env = malloc(sizeof(t_fdf));
		ft_init(argv[1], &(*env));
		mlx_image_to_window((*env)->win->mlx, (*env)->win->image, 0, 0);
		ft_draw_map((*env)->win->image, &(*env));
		mlx_key_hook((*env)->win->mlx, &key_hook, &(*env));
		mlx_resize_hook((*env)->win->mlx, handle_resize, &(*env));
		mlx_close_hook((*env)->win->mlx, &ft_close_window, &(*env));
		if (*env != NULL)
			mlx_loop((*env)->win->mlx);
		mlx_terminate((*env)->win->mlx);
		ft_free_env(&(*env));
	}
	else
		ft_return_error("Usage: ./fdf <filename>", 0);
}
