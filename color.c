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

double	power_of_n(double x, int n)
{
	double	res;

	res = 1;
	while (n--)
		res = res * x;
	return (res);
}

double	sqrt(double x)
{
	double	temp;
	double	sqrt;

	temp = 0;
	sqrt = x / 2;
	while (sqrt != temp)
	{
		temp = sqrt;
		sqrt = ((x / temp) + temp) / 2;
	}
	return (sqrt);
}

double	find_mod(double a, double b)
{
	double	mod;

	mod = a;
	if (b < 0)
		b = -b;
	while (mod > b)
		mod = mod - b;
	return (mod);
}

double	color_change(t_mlx *mlx)
{
	double	v;
	double	d;
	double	res;

	d = power_of_n(((double)mlx->iters / (double)MAX_ITER), 3);
	res = power_of_n(d * 15, 2) / sqrt(d * 15);
	v = find_mod(res, 15);
	return (v);
}

void	color(int keycode, t_mlx *coord)
{
	if (keycode == 0)
		coord->color = 25582242;
	else if (keycode == 1)
		coord->color = 255255255;
	else if (keycode == 2)
		coord->color = 233160160;
	else if (keycode == 13)
		coord->color = 163128203;
}
