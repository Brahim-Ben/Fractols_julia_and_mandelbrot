/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_function_partII.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:42:04 by bbenaali          #+#    #+#             */
/*   Updated: 2025/02/18 16:27:28 by bbenaali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(void)
{
	ft_putstr("Error Whit Malloc!\n");
	exit(1);
}

void	ini_variables(t_data *data)
{
	data->y = -1;
	data->itr = 0;
	data->color = 0;
}

int	for_exit(t_data *data)
{
	mlx_destroy_image(data->mlx_connection, data->imgss.img_ptr);
	mlx_destroy_window(data->mlx_connection, data->mlx_window);
	exit(1);
	return (0);
}

void	ft_for_fractol_render(t_data *data)
{
	data->color = (((data->itr * 255 / data->loop_number))
			<< (9 + data->colorshift)) & 0xFFFFFF;
	if (data->color == BLACK
		&& (data->real * data->real) + (data->img * data->img) <= 4)
		data->color = (data->itr * 255 / data->loop_number) << 6;
}
