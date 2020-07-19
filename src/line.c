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

void	safe_print(t_frac *frac, t_point a)
{
	int n;

	n = a.x * WIDTH + a.y;
	if (n < (WIDTH - 1) * WIDTH + WIDTH && n > 0 && a.y > 0 && a.y < WIDTH)
		frac->pix_m[a.x * WIDTH + a.y] = a.color;
}

void	print_line1(t_frac *frac, t_point a, t_line l)
{
	int d;
	int d1;
	int d2;
	int i;

	safe_print(frac, a);
	a.x += l.sx;
	i = 1;
	d = (l.dy << 1) - l.dx;
	d1 = l.dy << 1;
	d2 = (l.dy - l.dx) << 1;
	while (i < l.dx)
	{
		if (d > 0)
		{
			d += d2;
			a.y += l.sy;
		}
		else
			d += d1;
		safe_print(frac, a);
		a.x += l.sx;
		i++;
	}
}

void	print_line2(t_frac *frac, t_point a, t_line l)
{
	int d;
	int d1;
	int d2;
	int i;

	d = (l.dx << 1) - l.dy;
	d1 = l.dx << 1;
	d2 = (l.dx - l.dy) << 1;
	safe_print(frac, a);
	a.y += l.sy;
	i = 1;
	while (i <= l.dy)
	{
		if (d > 0)
		{
			d += d2;
			a.x += l.sx;
		}
		else
			d += d1;
		safe_print(frac, a);
		a.y += l.sy;
		i++;
	}
}

void	print_line(t_frac *frac, t_point a, t_point b)
{
	t_line		l;

	l.dx = (b.x > a.x) ? (b.x - a.x) : (a.x - b.x);
	l.dy = (b.y > a.y) ? (b.y - a.y) : (a.y - b.y);
	l.sx = (b.x >= a.x) ? (1) : (-1);
	l.sy = (b.y >= a.y) ? (1) : (-1);
	if (l.dy < l.dx)
		print_line1(frac, a, l);
	else
		print_line2(frac, a, l);
}
