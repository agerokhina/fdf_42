/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:13:13 by aerokhin          #+#    #+#             */
/*   Updated: 2025/01/07 17:23:34 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_fdffree(void **ptr)
{
	if (ptr == NULL)
		return ;
	free(*ptr);
}

void	ft_free_map(t_point ***map, int height)
{
	int	i;

	if (*map == NULL)
		return ;
	i = 0;
	while (i < height)
	{
		if ((*map)[i])
			ft_fdffree((void **)&((*map)[i]));
		i++;
	}
	ft_fdffree((void **)map);
	*map = NULL;
}

void	ft_free_arr(char **res, size_t i, char **str)
{
	ft_free(&(*str));
	while (i > 0)
	{
		ft_free(&(res[i - 1]));
		i--;
	}
	free(res);
}

void	ft_free_env(t_fdf **env)
{
	if ((*env)->map)
		ft_free_map(&((*env)->map), (*env)->map_settings.size.height);
	if ((*env)->win != NULL)
	{
		if ((*env)->win->image != NULL)
			mlx_delete_image((*env)->win->mlx, (*env)->win->image);
		if ((*env)->win->mlx != NULL)
		{
			mlx_close_window((*env)->win->mlx);
			mlx_terminate((*env)->win->mlx);
		}
		free((*env)->win);
	}
	free(*env);
	*env = NULL;
}
