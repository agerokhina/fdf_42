/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:09:41 by aerokhin          #+#    #+#             */
/*   Updated: 2025/01/11 16:21:42 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "get_next_line.h"
# include "libft.h"
# include "ft_printf.h"
# include <MLX42/MLX42.h>
# include <MLX42/MLX42_Int.h>
# include <errno.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>

# ifndef WIDTH
#  define WIDTH 2980
# endif
# ifndef HEIGHT
#  define HEIGHT 2000
# endif

# define GRADIENT_MIN 0xFFFFFFFF
# define GRADIENT_MAX 0xFF0000FF

# define ISOMETRIC 0
# define DIMETRIC 1
# define TOP 2

# define MAPS_SCALE 25

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef struct s_point
{
	float			x;
	float			y;
	float			z;
	int32_t			c;
}				t_point;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}				t_color;

typedef struct s_pixel
{
	int				x;
	int				y;
	t_color			c;
}				t_pixel;

typedef struct s_mlx_key_data
{
	int32_t	key;
	int32_t	action;
	int32_t	mods;
}	t_mlx_key_data;

typedef struct s_rotation
{
	float	alpha;
	float	beta;
	float	gamma;
}				t_rotation;

typedef struct s_size
{
	int	height;
	int	width;
}			t_size;

typedef struct s_pos
{
	int	i;
	int	j;
}			t_pos;

typedef struct s_maps_settings
{
	t_rotation	rotation;
	float		scale;
	int			proj;
	t_size		size;
	float		z_min;
	float		z_max;
	int			center_x;
	int			center_y;
	int			win_width;
	int			win_height;
}				t_maps_settings;

typedef struct s_mlx_window
{
	mlx_t		*mlx;
	mlx_image_t	*image;
}				t_mlx_windows;

typedef struct s_fdf
{
	t_point				**map;
	t_mlx_windows		*win;
	t_maps_settings		map_settings;
}				t_fdf;

typedef struct s_line
{
	float		dx;
	float		dy;
	float		sx;
	float		sy;
	float		err;
	float		e2;
}				t_line;

// File functions
int		ft_fdinit(const char *path);
int		ft_get_width(const char *filename);
int		ft_get_height(const char *filename);
void	ft_fd_close(int fd);
t_point	**ft_arrread(int fd, t_size size);

// Graphics functions
void	ft_drawline(mlx_image_t *img, \
					t_pixel x1, t_pixel x2, t_maps_settings map);
void	ft_put_line(mlx_image_t *image, t_point p1, t_point p2, \
					t_maps_settings map);
void	ft_draw_map(mlx_image_t *image, t_fdf **env);
void	ft_last_line(mlx_image_t *image, t_fdf **env);

// Color functions
int32_t	ft_pixel(t_color p);
t_color	interpolate_color(t_color c1, t_color c2, float t);
t_color	ft_color_from_int(int32_t color);

// Mathematition functions
void	rotate_point(t_point *point, t_rotation angles);
int32_t	ft_atoi_base(char *str, char *base);
t_point	ft_scale_coord(t_point point);

// Projection functions
t_pixel	isometric_projection(t_point point, float scale, t_rotation rotation);
t_pixel	dimetric_projection(t_point point, float scale, t_rotation rotation);
t_pixel	top_projection(t_point point, float scale);

// Utilites functions
void	ft_return_error(char *err_msg, int system_function);
t_point	ft_point(float x, float y, float z, int32_t color);
void	ft_print_arr(t_point **map, t_maps_settings set);
void	ft_print_env(t_fdf *env, char *title);
void	ft_print_color(char *title, t_color color);

//Freeing functions
void	ft_free_map(t_point ***map, int height);
void	ft_free_env(t_fdf **env);
void	ft_free_arr(char **res, size_t i, char **str);

//Initializing functions
void	ft_init_env(char *filename, t_fdf **env);
void	ft_init(char *filename, t_fdf **env);
void	ft_init_mapsettintgs(t_maps_settings *map_settings);

// Maps functions
t_point	ft_dec(char *str, int base);
void	ft_find_z_min_max(t_fdf **env);
void	ft_refill_color(t_fdf **env);

// Hooks functions
void	key_hook(mlx_key_data_t keydata, void *param);
void	handle_resize(int width, int height, void *param);
void	ft_hook(void *param);
void	ft_close_window(void *param);

#endif