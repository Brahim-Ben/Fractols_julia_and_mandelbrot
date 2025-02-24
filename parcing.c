/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 08:42:16 by bbenaali          #+#    #+#             */
/*   Updated: 2025/02/18 16:27:54 by bbenaali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	digit(char str)
{
	int	i;

	i = 0;
	if (str >= '0' && str <= '9')
		return (1);
	return (0);
}

static void	check_poin(char *s)
{
	int	i;
	int	count;
	int	add;

	i = 0;
	count = 0;
	add = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '.')
			count++;
		i++;
	}
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ' && s[i] != '\t')
			add++;
		i++;
	}
	if (count > 1)
		(ft_putstr("Error Parcing !\n"), exit(1));
	if (add == 0)
		(ft_putstr("Error Parcing !\n"), exit(1));
}

static void	sing(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == '-' || s[i] == '+') && ((s[i + 1] == '-'
					|| s[i + 1] == '+') || !digit(s[i + 1])))
			(ft_putstr("Error Parcing !\n"), exit(1));
		i++;
	}
}

void	check_parcing(char *s)
{
	int	i;

	i = 0;
	check_poin(s);
	sing(s);
	while (s[i] != '\0')
	{
		if (((s[i] == '.' && (!digit(s[i + 1])))
				|| (!digit(s[i]) && s[i] != '.' && s[i] != ' '
					&& s[i] != '\t')) && (s[i] != '+' && s[i] != '-'))
			(ft_putstr("Error Parcing !\n"), exit(1));
		i++;
	}
}
