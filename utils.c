/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-joul <yel-joul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:20:15 by yel-joul          #+#    #+#             */
/*   Updated: 2025/03/27 19:59:29 by yel-joul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_mlx.h"

void	clear(t_info *s)
{
	if (s->image)
	{
		mlx_destroy_image(s->mlx, s->image);
		s->image = NULL;
	}
	if (s->window)
	{
		mlx_destroy_window(s->mlx, s->window);
		s->window = NULL;
	}
	if (s->mlx)
	{
		mlx_destroy_display(s->mlx);
		free(s->mlx);
		s->mlx = NULL;
	}
	exit(0);
}

int	handle_mouse(int button, int x, int y, t_info *s)
{
	(void)x;
	(void)y;
	if (button == 4)
		s->zoom *= 1.13;
	else if (button == 5)
		s->zoom /= 1.13;
	draw_julia(s, s->c_real, s->c_imag);
	return (0);
}

int	hhandle_mouse(int button, int x, int y, t_info *s)
{
	(void)x;
	(void)y;
	if (button == 4)
		s->zoom *= 1.1;
	else if (button == 5)
		s->zoom /= 1.1;
	draw_mandelbrot(s);
	return (0);
}

int	win_close(t_info *s)
{
	clear(s);
	return (0);
}

int	esc_close(int key, t_info *s)
{
	if (key == 65307)
		clear(s);
	return (0);
}
