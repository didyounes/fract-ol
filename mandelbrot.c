/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-joul <yel-joul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:48:16 by yel-joul          #+#    #+#             */
/*   Updated: 2025/03/13 11:43:04 by yel-joul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_mlx.h"

static int	mandelbrot(double rel, double img)
{
	double	tmp;
	double	b;
	double	a;
	int		max_iter;
	int		iter;

	iter = 0;
	a = rel;
	b = img;
	max_iter = 100;
	while (((a * a) + (b * b)) < 4 && iter < max_iter)
	{
		tmp = a;
		a = (a * a) - (b * b) + rel;
		b = (2 * tmp * b) + img;
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
		color = 0x0000FF + ((iter - 20) * 0x0000FF / 20);
	else if (iter < 60)
		color = 0x00FFFF - ((iter - 40) * 0xFF0000 / 20);
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

static void	calculate_mandelbrot_set(t_info *s)
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
			iter = mandelbrot(rel, img);
			handle_pixel_color(s, j, i, iter);
			j++;
		}
		i++;
	}
}

void	draw_mandelbrot(t_info *s)
{
	calculate_mandelbrot_set(s);
	mlx_put_image_to_window(s->mlx, s->window, s->image, 0, 0);
}
