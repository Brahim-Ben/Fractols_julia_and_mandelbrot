/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:00:07 by bbenaali          #+#    #+#             */
/*   Updated: 2025/02/18 16:27:44 by bbenaali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_pixel_put(t_imag *img, int x, int y, int color)
{
	int	offset;

	offset = (img->size_line * y) + (x * (img->bits_per_pixel / 8));
	*((unsigned int *)(offset + img->pixels_ptr)) = color;
}

double	map(double n, t_map map)
{
	return ((map.new_max - map.new_min) * n / map.old_max + map.new_min);
}

t_com	sum_comp(t_com z1, t_com z2)
{
	t_com	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_com	squa_comp(t_com z)
{
	t_com	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}
