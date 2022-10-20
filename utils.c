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

double	map_real_part(double x, double width, double min_r, double max_r)
{
	double	range;

	range = max_r - min_r;
	return (x * (range / width) + min_r);
}

double	map_img_part(double y, double height, double min_i, double max_i)
{
	return (y * ((max_i - min_i) / height) + min_i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
}
