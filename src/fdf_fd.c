/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:37:36 by aerokhina         #+#    #+#             */
/*   Updated: 2025/01/07 17:23:37 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	ft_fdinit(const char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_return_error("Error: failed to open file!", 1);
	return (fd);
}

void	ft_fd_close(int fd)
{
	char	*line;

	line = gnl(fd);
	while (line != NULL)
	{
		ft_free(&line);
		line = gnl(fd);
	}
	ft_free(&line);
	close(fd);
}

int	ft_get_height(const char *filename)
{
	int		fd;
	int		height;
	char	*line;

	fd = ft_fdinit(filename);
	height = 0;
	line = gnl(fd);
	while (line != NULL)
	{
		height++;
		ft_free(&line);
		line = gnl(fd);
	}
	close(fd);
	return (height);
}

int	ft_get_width(const char *filename)
{
	int		fd;
	int		width;
	char	*line;
	char	**arr;

	fd = ft_fdinit(filename);
	line = gnl(fd);
	if (line == NULL)
		ft_return_error("Error: failed to read line", 1);
	arr = ft_split(line, ' ');
	if (arr == NULL)
		ft_return_error("Error: failed to split line", 1);
	width = 0;
	while (arr[width] != NULL)
		width++;
	ft_free_arr(&(*arr), width, &line);
	ft_fd_close(fd);
	return (width);
}

t_point	**ft_arrread(int fd, t_size size)
{
	t_point	**map;
	char	*line;
	char	**arr;
	t_pos	p;

	map = (t_point **)malloc(sizeof(t_point *) * size.height);
	if (map == NULL)
		ft_return_error("Error: failed to allocate memory", 1);
	p.i = -1;
	while (++p.i < size.height)
	{
		map[p.i] = (t_point *)malloc(sizeof(t_point) * size.width);
		line = gnl(fd);
		if (map[p.i] == NULL || line == NULL)
			ft_return_error("Error: failed in map/line", 1);
		arr = ft_split(line, ' ');
		if (arr == NULL)
			ft_return_error("Error: failed in split", 1);
		p.j = -1;
		while (++p.j < size.width)
			map[p.i][p.j] = ft_point((float)p.i, (float)p.j, \
			(float)(ft_dec(arr[p.j], 10).z), (ft_dec(arr[p.j], 16).c));
		ft_free_arr(&(*arr), size.width, &line);
	}
	return (close(fd), map);
}
