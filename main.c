/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-joul <yel-joul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:27:16 by yel-joul          #+#    #+#             */
/*   Updated: 2025/03/29 01:44:15 by yel-joul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_mlx.h"

static int	init_mlx(t_info *s)
{
	s->mlx = mlx_init();
	if (!s->mlx)
		return (1);
	s->window = mlx_new_window(s->mlx, WIDTH, HEIGHT, "Fract-ol");
	if (!s->window)
		return (clear(s), 1);
	s->image = mlx_new_image(s->mlx, WIDTH, HEIGHT);
	if (!s->image)
		return (clear(s), 1);
	s->addr = mlx_get_data_addr(s->image, &s->bits_per_pixel,
			&s->line_length, &s->endian);
	if (!s->addr)
		return (clear(s), 1);
	mlx_put_image_to_window(s->mlx, s->window, s->image, 0, 0);
	mlx_key_hook(s->window, esc_close, s);
	mlx_hook(s->window, 17, 0, win_close, s);
	return (0);
}

int	init_mlx_wrapper(t_info *s, int ac, char **av)
{
	s->zoom = 1.0;
	if (ac < 2 || ac > 4 || ac == 3)
		return (ft_putstr("Usage: ./fractol [julia/mandelbrot]\n"), 1);
	else if ((ft_strcmp(av[1], "Julia") != 0)
		&& (ft_strcmp(av[1], "Mandelbrot") != 0))
	{
		ft_putstr("Available parameters: julia and mandelbrot\n");
		exit(1);
	}
	else if (init_mlx(s) != 0)
		return (1);
	return (0);
}

void	setup_mandelbrot(t_info *s)
{
	draw_mandelbrot(s);
	mlx_mouse_hook(s->window, hhandle_mouse, s);
}

void	f_func(double i, double j)
{
	if (!(i >= -2 && i <= 2 && j >= -2 && j <= 2))
	{
		ft_putstr("Invalid Numbers\n");
		exit(1);
	}
}

int	main(int ac, char *av[])
{
	t_info	s;

	if (init_mlx_wrapper(&s, ac, av) != 0)
		return (1);
	else if (ft_strcmp(av[1], "Julia") == 0 && ac == 4
		&& is_valid_number(av[2]) && is_valid_number(av[3]))
	{
		s.c_real = c_str_d(av[2]);
		s.c_imag = c_str_d(av[3]);
		f_func(s.c_real, s.c_imag);
		draw_julia(&s, s.c_real, s.c_imag);
		mlx_mouse_hook(s.window, handle_mouse, &s);
	}
	else if (ac == 2 && ft_strcmp(av[1], "Julia") == 0)
	{
		s.c_imag = 0.8;
		draw_julia(&s, 0, s.c_imag);
		mlx_mouse_hook(s.window, handle_mouse, &s);
	}
	else if (ft_strcmp(av[1], "Mandelbrot") == 0 && ac == 2)
		setup_mandelbrot(&s);
	else
		return (ft_putstr("Available parameters: julia and mandelbrot\n"),
			clear(&s), 1);
	mlx_loop(s.mlx);
}
