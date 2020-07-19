/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 17:39:30 by gweasley          #+#    #+#             */
/*   Updated: 2020/03/08 17:39:31 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		is_mand(double x, double y, int n)
{
	int		i;
	double	z_x;
	double	z_y;
	double	tmp_x;

	i = 0;
	z_x = x;
	z_y = y;
	while (i < n)
	{
		tmp_x = z_x * z_x - z_y * z_y + x;
		z_y = 2 * z_x * z_y + y;
		z_x = tmp_x;
		if ((z_x * z_x + z_y * z_y) > 4)
			break ;
		i++;
	}
	return (i);
}

int		is_julia(double x, double y, t_frac *frac)
{
	int		i;
	double	z_x;
	double	z_y;
	double	tmp_x;
	double	r;

	i = 0;
	z_x = x;
	z_y = y;
	r = (1 + sqrt(1 + 4 * sqrt(frac->c_x * frac->c_x +
		frac->c_y * frac->c_y))) / 2;
	while (i < frac->num_of_iter)
	{
		tmp_x = z_x * z_x - z_y * z_y + frac->c_x;
		z_y = 2 * z_x * z_y + frac->c_y;
		z_x = tmp_x;
		if (z_x * z_x + z_y * z_y > r * r)
			return (i);
		i++;
	}
	return (i);
}

void	julia(t_frac *frac)
{
	int		i;
	int		j;
	double	x;
	double	y;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		y = (i - WIDTH / 2) + frac->shift_y;
		y /= frac->scale;
		while (j < WIDTH)
		{
			x = j - WIDTH / 2 + frac->shift_x;
			x /= frac->scale;
			frac->pix_m[i * WIDTH + j] = put_color(frac, is_julia(x, y, frac));
			j++;
		}
		i++;
	}
}

void	mandelbrot(t_frac *frac)
{
	int		i;
	int		j;
	double	x;
	double	y;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		y = (i - WIDTH / 2) + frac->shift_y;
		y /= frac->scale;
		while (j < WIDTH)
		{
			x = j - WIDTH / 2 + frac->shift_x;
			x /= frac->scale;
			frac->pix_m[i * WIDTH + j] = put_color(frac,
			is_mand(x, y, frac->num_of_iter));
			j++;
		}
		i++;
	}
}
