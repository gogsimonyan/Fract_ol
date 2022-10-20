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

int	iterate_mandelbrot(t_mlx *mlx)
{
	int		iters;
	double	x;
	double	y;
	double	x0;
	double	y0;

	iters = 0;
	mlx->complex.cre = mlx->x / mlx->scale + mlx->complex.re;
	mlx->complex.cim = mlx->y / mlx->scale + mlx->complex.im;
	x0 = mlx->complex.cre;
	y0 = mlx->complex.cim;
	while (iters <= MAX_ITER)
	{
		if (mlx->complex.cim * mlx->complex.cim + \
				mlx->complex.cre * mlx->complex.cre > 4)
			break ;
		x = mlx->complex.cre * mlx->complex.cre - \
			mlx->complex.cim * mlx->complex.cim;
		y = 2 * mlx->complex.cre * mlx->complex.cim;
		mlx->complex.cre = x + x0;
		mlx->complex.cim = y + y0;
		iters++;
	}
	return (iters);
}

int	iterate_julia(t_mlx *mlx)
{
	double	x;
	double	y;
	int		iters;

	iters = 0;
	mlx->complex.cre = mlx->x / mlx->scale + mlx->complex.re;
	mlx->complex.cim = mlx->y / mlx->scale + mlx->complex.im;
	while (iters <= MAX_ITER)
	{
		if (mlx->complex.cim * mlx->complex.cim + \
				mlx->complex.cre * mlx->complex.cre > 4)
			break ;
		x = mlx->complex.cre * mlx->complex.cre - \
			mlx->complex.cim * mlx->complex.cim;
		y = 2 * mlx->complex.cre * mlx->complex.cim;
		mlx->complex.cre = x + mlx->complex.jre;
		mlx->complex.cim = y + mlx->complex.jim;
		iters++;
	}
	return (iters);
}
