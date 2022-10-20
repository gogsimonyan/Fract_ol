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

void	draw_point(int x, int y, t_mlx *mlx)
{
	int	memory_offset;

	if (mlx->code)
		mlx->iters = iterate_julia(mlx);
	else
		mlx->iters = iterate_mandelbrot(mlx);
	memory_offset = y * mlx->image.line_length + \
					x * (mlx->image.bits_per_pixel / 8);
	if (mlx->iters >= MAX_ITER)
		*(unsigned int *)(mlx->image.image_addr + memory_offset) = 0x000000;
	else
	{
		*(unsigned int *)(mlx->image.image_addr + memory_offset)
			= mlx->color * color_change(mlx);
	}
}

void	draw_fractol(t_mlx *mlx)
{
	mlx->x = 0;
	while (mlx->x < WIDTH)
	{
		mlx->y = 0;
		while (mlx->y < HEIGHT)
		{
			draw_point(mlx->x, mlx->y, mlx);
			mlx->y++;
		}
		mlx->x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image.image_ptr, 0, 0);
}
