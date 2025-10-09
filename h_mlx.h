/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_mlx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-joul <yel-joul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 01:41:10 by yel-joul          #+#    #+#             */
/*   Updated: 2025/03/28 00:10:35 by yel-joul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_MLX_H
# define H_MLX_H

# include "/home/yel-joul/minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 729
# define HEIGHT 729

typedef struct s_info
{
	void	*mlx;
	void	*window;
	void	*image;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	c_real;
	double	c_imag;
	double	zoom;
}			t_info;

void	draw_julia(t_info *s, double c_rel, double c_img);
void	my_mlx_pixel_put(t_info *s, int x, int y, int color);
int		handle_mouse(int button, int x, int y, t_info *s);
int		hhandle_mouse(int button, int x, int y, t_info *s);
int		ft_strcmp(char *str1, char *str2);
int		esc_close(int key, t_info *s);
int		win_close(t_info *s);
void	clear(t_info *s);
double	c_str_d(char *str);
void	draw_mandelbrot(t_info *s);
void	ft_putstr(char *str);
int		is_valid_number(char *str);
#endif
