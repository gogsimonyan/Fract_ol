/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:41:29 by gsimonya          #+#    #+#             */
/*   Updated: 2022/10/13 19:41:37 by gsimonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H

# define FRACT_OL_H

# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

# ifdef LINUX
#  include "minilibx-linux/mlx.h"
#define ESC 65307
#define UP 65362
#define DOWN 65364
#define LEFT 65361
#define RIGHT 65363
# else
#  include <mlx.h>

#  define ESC 53
#  define UP_A 126
#  define DOWN_A 125
#  define LEFT_A 123
#  define RIGHT_A 124
# endif

# define SCROLL_UP 4
# define SCROLL_DOWN 5

# define MAX_ITER 100

# define WIDTH 800
# define HEIGHT 800

typedef struct s_complex
{
	double	re;
	double	im;
	double	cre;
	double	cim;
	double	jre;
	double	jim;
}	t_complex;

typedef struct s_image
{
	void	*image_ptr;
	char	*image_addr;
	int		line_length;
	int		bits_per_pixel;
	int		endian;
}	t_image;

typedef struct s_mlx
{
	void		*mlx;
	void		*window;
	t_image		image;
	double		scale;
	int			x;
	int			y;
	int			code;
	int			iters;
	int			color;
	t_complex	complex;
}	t_mlx;

int		key_pressed(int key_code, t_mlx *mlx);
int		mouse_pressed(int key_code, int x, int y, t_mlx *mlx);
int		iterate_mandelbrot(t_mlx *mlx);
int		iterate_julia(t_mlx *mlx);
void	draw_point(int x, int y, t_mlx *mlx);
void	draw_fractol(t_mlx *mlx);
int		clean_and_exit(t_mlx *mlx);
void	color(int keycode, t_mlx *coord);
double	color_change(t_mlx *mlx);
double	map_real_part(double x, double width, double min_r, double max_r);
double	map_img_part(double y, double height, double min_i, double max_i);
int		julia_animation(int x, int y, t_mlx *mlx);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr(char *s);

#endif