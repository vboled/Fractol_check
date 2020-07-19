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

#include "fractol.h"

void	paint(t_frac *frac, t_point *a, t_point *b, int k)
{
	t_point new_point;

	if (!k)
	{
		print_line(frac, *a, *b);
		return ;
	}
	new_point.x = (int)(a->x + b->x) / 2 + (int)(b->y - a->y) / 2;
	new_point.y = (int)(a->y + b->y) / 2 - (int)(b->x - a->x) / 2;
	new_point.color = (*a).color;
	paint(frac, b, &new_point, k - 1);
	paint(frac, a, &new_point, k - 1);
}

void	paint_dragon(t_frac *frac, int x, int y, int color)
{
	t_point		a;
	t_point		b;

	a.color = color;
	b.color = color;
	a.x = (400 - frac->shift_y) * frac->scale / 100;
	b.x = (x - frac->shift_y) * frac->scale / 100;
	a.y = (400 - frac->shift_x) * frac->scale / 100;
	b.y = (y - frac->shift_x) * frac->scale / 100;
	paint(frac, &a, &b, frac->num_of_iter);
}

void	dragon(t_frac *frac)
{
	if (frac->num_of_dragon)
		paint_dragon(frac, 100, 100, 0xFF0000);
	if (frac->num_of_dragon >= 2)
		paint_dragon(frac, 700, 100, 0x1D1AB2);
	if (frac->num_of_dragon >= 3)
		paint_dragon(frac, 700, 700, 0x5DE100);
	if (frac->num_of_dragon >= 4)
		paint_dragon(frac, 100, 700, 0xFFE800);
}
