/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 09:12:17 by bbenaali          #+#    #+#             */
/*   Updated: 2025/02/18 16:27:03 by bbenaali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define ERROR "Error: please respect the compilation command:\n\
\t./fractol <write (Mandelbrot) , (Julia) or (\"Burning Ship\")>\n\
\t\tif chose julia write the coordinate (x and y)\n"

# define WIDTH 800
# define HIEGHT 800
# define BLACK       0x000000

typedef struct s_imag
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_imag;

typedef struct s_com
{
	double	x;
	double	y;
}	t_com;

typedef struct s_data
{
	void	*mlx_connection;
	void	*mlx_window;
	char	*name;
	double	real_julia;
	double	imag_julia;
	double	sh_left;
	double	sh_right;
	double	zoom;
	int		y;
	int		x;
	int		color;
	double	real ;
	double	img;
	int		itr;
	double	offset_x;
	double	offset_y;
	double	color_shilft;
	int		loop_number;
	int		colorshift;
	t_imag	imgss;
}	t_data;

typedef struct s_map
{
	double	new_min;
	double	new_max;
	double	old_max;
}	t_map;

int		mouse_hook(int button, int x, int y, t_data *fractol);
int		key_hand(int key, t_data *data);
void	for_open_window(t_data *data);
void	fractol_render(t_data *data);
int		ft_burning_ship(double x, double y, t_data *var);
int		ft_strcmp(char *s1, char *s2);
void	ft_error(void);
void	ini_variables(t_data *data);
int		for_exit(t_data *data);
void	ft_for_fractol_render(t_data *data);
void	my_pixel_put(t_imag *img, int x, int y, int color);
double	map(double n, t_map map);
t_com	sum_comp(t_com z1, t_com z2);
t_com	squa_comp(t_com z);
void	ft_putstr(char *str);
void	check_parcing(char *s);

#endif