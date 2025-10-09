/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_str_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-joul <yel-joul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:39:03 by yel-joul          #+#    #+#             */
/*   Updated: 2025/02/24 21:08:11 by yel-joul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_mlx.h"

static double	helper(char *str)
{
	int		i;
	double	place;
	double	result;

	i = 0;
	place = 0.1;
	result = 0.0;
	while (str[i] && str[i] != '.')
		i++;
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			result = result + ((str[i] - '0') * place);
			place *= 0.1;
			i++;
		}
	}
	return (result);
}

double	c_str_d(char *str)
{
	int		i;
	int		sign;
	double	result;

	i = 0;
	sign = 1;
	result = 0.0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	result += helper(str);
	return (result * sign);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

void	my_mlx_pixel_put(t_info *s, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = s->addr + (y * s->line_length + x * (s->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
