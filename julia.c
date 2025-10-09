/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-joul <yel-joul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:01:13 by yel-joul          #+#    #+#             */
/*   Updated: 2025/02/17 15:26:11 by yel-joul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_mlx.h"

static int	julia(double rel, double img, double c_rel, double c_img)
{
	double	tmp;
	int		max_iter;
	double	a;
	double	b;
	int		iter;

	iter = 0;
	max_iter = 100;
	a = rel;
	b = img;
	while (((a * a) + (b * b)) < 4 && iter < max_iter)
	{
		tmp = a;
		a = (a * a) - (b * b) + c_rel;
		b = 2 * tmp * b + c_img;
		iter++;
	}
	return (iter);
}

static int	calculate_color(int iter)
{
	int	color;

	if (iter == 100)
		return (0x000000);
	if (iter < 20)
		color = 0x000000 + (iter * 0x0000FF / 20);
	else if (iter < 40)
		color = 0x0000FF + ((iter - 20) * 0x00FF00 / 20);
	else if (iter < 60)
		color = 0x00FFFF - ((iter - 40) * 0x0000FF / 20);
	else if (iter < 80)
		color = 0x00FF00 + ((iter - 60) * 0xFF0000 / 20);
	else
		color = 0xFFFF00 - ((iter - 80) * 0x00FF00 / 20);
	return (color);
}

static void	handle_pixel_color(t_info *s, int j, int i, int iter)
{
	int	color;

	if (iter == 100)
		my_mlx_pixel_put(s, j, i, 0x000000);
	else
	{
		color = calculate_color(iter);
		my_mlx_pixel_put(s, j, i, color);
	}
}

static void	calculate_julia_set(t_info *s, double c_rel, double c_img)
{
	int		i;
	int		j;
	int		iter;
	double	rel;
	double	img;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			rel = (j - WIDTH / 2.0) * 3.0 / WIDTH * (1 / s->zoom);
			img = (i - HEIGHT / 2.0) * 3.0 / HEIGHT * (1 / s->zoom);
			iter = julia(rel, img, c_rel, c_img);
			handle_pixel_color(s, j, i, iter);
			j++;
		}
		i++;
	}
}

void	draw_julia(t_info *s, double c_rel, double c_img)
{
	calculate_julia_set(s, c_rel, c_img);
	mlx_put_image_to_window(s->mlx, s->window, s->image, 0, 0);
}
