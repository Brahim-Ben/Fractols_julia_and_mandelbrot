/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:44:52 by bbenaali          #+#    #+#             */
/*   Updated: 2025/02/18 12:37:41 by bbenaali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	handl(const char *str, double result)
{
	double	fraction;

	fraction = 0.1;
	str++;
	while (*str >= '0' && *str <= '9')
	{
		result += (*str - '0') * fraction;
		fraction /= 10;
		str++;
	}
	return (result);
}

static double	ft_atoi(const char *str)
{
	double	result;
	int		sign;
	double	fraction;

	fraction = 0.1;
	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			sign = -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (*str == '.')
		result = handl(str, result);
	return (result * sign);
}

static void	inisialise_variables(t_data *data)
{
	data->sh_left = 0;
	data->sh_right = 0;
	data->zoom = 1;
	data->offset_x = 0.0;
	data->offset_y = 0.0;
	data->loop_number = 200;
	data->colorshift = 1;
}

int	main(int ac, char *av[])
{
	t_data	data;

	if ((ac == 2 && !ft_strcmp(av[1], "Mandelbrot"))
		|| (ac == 4 && !ft_strcmp(av[1], "Julia"))
		|| (ac == 2 && !ft_strcmp(av[1], "Burning Ship")))
	{
		if (!ft_strcmp(av[1], "Julia"))
		{
			check_parcing(av[2]);
			check_parcing(av[3]);
			data.real_julia = ft_atoi(av[2]);
			data.imag_julia = ft_atoi(av[3]);
		}
		data.name = av[1];
		inisialise_variables(&data);
		for_open_window(&data);
		fractol_render(&data);
		mlx_hook(data.mlx_window, 17, 0, for_exit, &data);
		mlx_mouse_hook(data.mlx_window, mouse_hook, &data);
		mlx_key_hook(data.mlx_window, key_hand, &data);
		mlx_loop(data.mlx_connection);
	}
	else
		ft_putstr(ERROR);
}
