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

#include "fract_ol.h"

int	key_pressed(int key_code, t_mlx *mlx)
{
	printf("%d\n", key_code);
	if (key_code == ESC)
		clean_and_exit(mlx);
	color(key_code, mlx);
	if (key_code == UP)
		mlx->complex.im -= 30 / mlx->scale;
	else if (key_code == RIGHT)
		mlx->complex.re += 30 / mlx->scale;
	else if (key_code == LEFT)
		mlx->complex.re -= 30 / mlx->scale;
	else if (key_code == DOWN)
		mlx->complex.im += 30 / mlx->scale;
	draw_fractol(mlx);
	return (0);
}

int	mouse_pressed(int key_code, int x, int y, t_mlx *mlx)
{
	if (key_code == SCROLL_DOWN)
	{
		mlx->complex.re = ((double)x / mlx->scale + mlx->complex.re) - \
						((double)x / (mlx->scale * 1.3));
		mlx->complex.im = ((double)y / mlx->scale + mlx->complex.im) - \
						((double)y / (mlx->scale * 1.3));
		mlx->scale *= 1.3;
	}
	else if (key_code == SCROLL_UP)
	{
		mlx->complex.re = ((double)x / mlx->scale + mlx->complex.re) - \
						((double)x / (mlx->scale / 1.3));
		mlx->complex.im = ((double)y / mlx->scale + mlx->complex.im) - \
						((double)y / (mlx->scale / 1.3));
		mlx->scale /= 1.3;
	}
	draw_fractol(mlx);
	return (0);
}

int	clean_and_exit(t_mlx *mlx)
{
	if (mlx->image.image_ptr)
	{
		mlx_destroy_image(mlx->mlx, mlx->image.image_ptr);
	}
	if (mlx->window)
	{
		mlx_destroy_window(mlx->mlx, mlx->window);
	}
	exit(EXIT_FAILURE);
}

int	julia_animation(int x, int y, t_mlx *mlx)
{
	mlx->complex.jre = map_real_part((double)x, WIDTH, -2, 2);
	mlx->complex.jim = map_img_part((double)y, HEIGHT, -2, 2);
	draw_fractol(mlx);
	return (0);
}
