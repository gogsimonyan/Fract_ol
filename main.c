/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:41:29 by gsimonya          #+#    #+#             */
/*   Updated: 2022/10/15 13:34:32 by gsimonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	init_window(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		exit(1);
	mlx->window = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "fract_ol");
	mlx->image.image_ptr = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (!mlx->window || !mlx->image.image_ptr)
	{
		clean_and_exit(mlx);
	}
	mlx->image.image_addr = mlx_get_data_addr(mlx->image.image_ptr,
			&mlx->image.bits_per_pixel,
			&mlx->image.line_length, &mlx->image.endian);
	if (!mlx->image.image_addr)
		clean_and_exit(mlx);
}

void	set_up_window(t_mlx *mlx)
{
	mlx->scale = 200;
	mlx->x = 0;
	mlx->y = 0;
	mlx->complex.re = -2.05;
	mlx->complex.im = -1.3;
	mlx->complex.jre = -0.5;
	mlx->complex.jim = -0.5;
	mlx->color = 72013;
	init_window(mlx);
	mlx_hook(mlx->window, 17, 0, &clean_and_exit, mlx);
	mlx_key_hook(mlx->window, &key_pressed, mlx);
	mlx_mouse_hook(mlx->window, &mouse_pressed, mlx);
	if (mlx->code)
		mlx_hook(mlx->window, 6, 1L << 6, &julia_animation, mlx);
	draw_fractol(mlx);
	mlx_loop(mlx->mlx);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc == 2)
	{
		if (!ft_strcmp("mandelbrot", argv[1]) || !ft_strcmp("julia", argv[1]))
		{
			mlx.code = !ft_strcmp(argv[1], "julia");
			set_up_window(&mlx);
		}
		ft_putstr("Usage: ./fract_ol mandelbrot || julia\n");
	}
	else
		ft_putstr("Usage: ./fract_ol mandelbrot || julia\n");
}
