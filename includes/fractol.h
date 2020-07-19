/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 13:49:34 by gweasley          #+#    #+#             */
/*   Updated: 2020/03/08 13:50:42 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 800
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "../libs/libft/libft.h"
# include <stdio.h>

typedef struct			s_line
{
	int					dx;
	int					dy;
	int					sx;
	int					sy;
}						t_line;

typedef struct			s_point
{
	int					x;
	int					y;
	int					color;
}						t_point;

typedef struct			s_frac
{
	struct s_frac		*next;
	struct s_frac		*head;
	void				*mlx;
	void				*win;
	void				*img;
	int					*pix_m;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	double				shift_x;
	double				shift_y;
	int					scale_step;
	int					scale;
	int					pix_m_size;
	int					color_scheme;
	int					mouse_x;
	int					mouse_y;
	double				c_x;
	double				c_y;
	int					old_x;
	int					old_y;
	int					z_change;
	int					type;
	int					num_of_iter;
	int					num_of_str;
	int					num_of_dragon;
}						t_frac;

void					dragon(t_frac *frac);
void					print_line(t_frac *frac, t_point a, t_point b);
void					destroy_window(t_frac *frac);
int						deal_hook(int key, t_frac *param);
void					frac_init(t_frac *frac, int type, void *mlx);
void					shift(t_frac *frac, int key);
int						mem_alloc(t_frac *frac);
void					free_list_frac(t_frac *frac);
void					scale_key(t_frac *frac, int key);
void					create_mlx_image(t_frac *frac);
void					mandelbrot(t_frac *frac);
int						add_frac(t_frac **frac, int type);
int						mouse_hook(int key, int x, int y, void *param);
int						put_color(t_frac *frac, int iter);
void					mouse_wheel(t_frac *frac, int key, int x, int y);
void					change_iter(t_frac *frac, int key);
void					julia(t_frac *frac);
int						get_color(int begin, int end, double percent);
void					change_dragon(t_frac *frac, int key);
void					change_color(t_frac *frac);
void					clear_window(t_frac *frac);
void					call_fractal(t_frac *frac);
int						color2(int iter);
void					change_flag(t_frac *frac);
int						mouse_motion(int x, int y, void *frac);
#endif
