/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burning_ship.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 09:26:04 by bbenaali          #+#    #+#             */
/*   Updated: 2025/02/18 16:27:21 by bbenaali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_com	sum_comp_bonus(t_com z1, t_com z2)
{
	t_com	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

static t_com	squa_comp_bonus(t_com z)
{
	t_com	result;

	result.x = fabs(z.x * z.x) - fabs(z.y * z.y);
	result.y = fabs(2 * z.x * z.y);
	return (result);
}

int	ft_burning_ship(double x, double y, t_data *var)
{
	int		i;
	t_com	z;
	t_com	c;

	i = 0;
	z.x = 0;
	z.y = 0;
	c.x = x;
	c.y = y;
	while ((z.x * z.x) + (z.y * z.y) <= 4 && i++ < var->loop_number)
		z = sum_comp_bonus(squa_comp_bonus(z), c);
	return (i);
}
