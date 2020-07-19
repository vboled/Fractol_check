/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:29:08 by gweasley          #+#    #+#             */
/*   Updated: 2020/03/11 14:29:09 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	call_mandelbrot(t_frac *frac)
{
	mlx_string_put(frac->mlx, frac->win, 30, 30 * frac->num_of_str++,
		0xFFFFFF, "Use mouse wheel for scaling");
	mandelbrot(frac);
}

void	call_julia(t_frac *frac)
{
	mlx_string_put(frac->mlx, frac->win, 30, 30 * frac->num_of_str++,
	0xFFFFFF, "Use mouse wheel for scaling");
	if (!frac->z_change)
	{
		mlx_string_put(frac->mlx, frac->win, 30, 30 * frac->num_of_str++,
		0xFFFFFF, "To starting change z, press SPACE");
	}
	else
	{
		mlx_string_put(frac->mlx, frac->win, 30, 30 * frac->num_of_str++,
		0xFFFFFF, "To stop change z, press SPACE");
	}
	julia(frac);
}

void	call_dragon(t_frac *frac)
{
	mlx_string_put(frac->mlx, frac->win, 30, 30 * frac->num_of_str++, 0xFFFFFF,
	"For change number of dragons press G/B");
	mlx_string_put(frac->mlx, frac->win, 30, 30 * frac->num_of_str++, 0xFFFFFF,
	"Use mouse wheel for scaling");
	dragon(frac);
}

void	call_fractal(t_frac *frac)
{
	if (frac->type == 1)
		call_mandelbrot(frac);
	if (frac->type == 2)
		call_julia(frac);
	if (frac->type == 3)
		call_dragon(frac);
}

void	clear_window(t_frac *frac)
{
	int		i;
	int		j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < WIDTH)
		{
			frac->pix_m[i * WIDTH + j] = 0;
			j++;
		}
		i++;
	}
}
