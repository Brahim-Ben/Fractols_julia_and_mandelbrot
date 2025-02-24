/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_open_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 09:11:28 by bbenaali          #+#    #+#             */
/*   Updated: 2025/02/18 16:27:13 by bbenaali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int key, int x, int y, t_data *fractol)
{
	double	mouse_x;
	double	mouse_y;
	double	zoom_factor;

	mouse_x = map(x, (t_map){-2, 2, WIDTH}) * fractol->zoom
		+ fractol->offset_x;
	mouse_y = map(y, (t_map){-2, 2, HIEGHT}) * fractol->zoom
		+ fractol->offset_y;
	if (key == 4)
		zoom_factor = 0.9;
	else if (key == 5)
		zoom_factor = 1.1;
	else
		return (0);
	fractol->offset_x = mouse_x + (fractol->offset_x - mouse_x) * zoom_factor;
	fractol->offset_y = mouse_y + (fractol->offset_y - mouse_y) * zoom_factor;
	fractol->zoom *= zoom_factor;
	fractol_render(fractol);
	return (0);
}

int	key_hand(int key, t_data *data)
{
	if (key == 53)
	{
		mlx_destroy_image(data->mlx_connection, data->imgss.img_ptr);
		mlx_destroy_window(data->mlx_connection, data->mlx_window);
		exit(1);
	}
	else if (key == 49)
		data->colorshift += 2;
	else if (key == 123)
		data->sh_left += 0.5;
	else if (key == 124)
		data->sh_left -= 0.5;
	else if (key == 125)
		data->sh_right -= 0.5;
	else if (key == 126)
		data->sh_right += 0.5;
	fractol_render(data);
	return (0);
}

static int	handel_pixels(t_data *data)
{
	t_com	z;
	t_com	c;
	int		i;

	i = 0;
	if (!ft_strcmp(data->name, "Julia"))
	{
		c.y = data->imag_julia;
		c.x = data->real_julia;
		z.x = data->real;
		z.y = data->img;
	}
	else if (!ft_strcmp(data->name, "Mandelbrot"))
	{
		z.x = 0;
		z.y = 0;
		c.x = data->real;
		c.y = data->img;
	}
	else
		return (ft_burning_ship(data->real, data->img, data));
	while ((z.x * z.x) + (z.y * z.y) <= 4 && i++ < data->loop_number)
		z = sum_comp(squa_comp(z), c);
	return (i);
}

void	fractol_render(t_data *data)
{
	ini_variables(data);
	while (++data->y < HIEGHT)
	{
		data->x = -1;
		while (++data->x < WIDTH)
		{
			data->real = (map(data->x, (t_map){-2, 2, WIDTH})) * data->zoom
				+ data->offset_x + data->sh_left;
			data->img = (map(data->y, (t_map){-2, 2, HIEGHT})) * data->zoom
				+ data->offset_y + data->sh_right;
			data->itr = handel_pixels(data);
			if (data->itr == data->loop_number)
				data->color = BLACK;
			else
				ft_for_fractol_render(data);
			my_pixel_put(&data->imgss, data->x, data->y, data->color);
		}
	}
	mlx_put_image_to_window(data->mlx_connection, data->mlx_window,
		data->imgss.img_ptr, 0, 0);
}

void	for_open_window(t_data *data)
{
	data->mlx_connection = mlx_init();
	if (!data->mlx_connection)
		ft_error();
	data->mlx_window = mlx_new_window(data->mlx_connection, WIDTH, HIEGHT,
			data->name);
	if (!data->mlx_window)
		ft_error();
	data->imgss.img_ptr = mlx_new_image(data->mlx_connection, WIDTH, HIEGHT);
	if (!data->imgss.img_ptr)
	{
		mlx_destroy_window(data->mlx_connection, data->mlx_window);
		ft_error();
	}
	data->imgss.pixels_ptr = mlx_get_data_addr(data->imgss.img_ptr,
			&data->imgss.bits_per_pixel,
			&data->imgss.size_line,
			&data->imgss.endian);
	if (!data->imgss.pixels_ptr)
	{
		mlx_destroy_image(data->mlx_connection, data->imgss.img_ptr);
		mlx_destroy_window(data->mlx_connection, data->mlx_window);
		ft_error();
	}
}
