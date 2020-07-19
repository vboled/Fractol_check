/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 17:23:36 by gweasley          #+#    #+#             */
/*   Updated: 2020/05/12 22:08:18 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mouse_wheel(t_frac *frac, int key, int x, int y)
{
	if (x >= 400 && x <= 1200 && y >= 50 && y <= 850)
	{
		if (key == 4)
			frac->scale -= 5;
		else
			frac->scale += 5;
		frac->mouse_x = 50;
		frac->mouse_y = 50;
		if (frac->scale <= 0)
			frac->scale = 200;
	}
}

void	scale_key(t_frac *frac, int key)
{
	if (key == 65451 || key == 69)
		frac->scale += frac->scale_step;
	else if (key == 65453 || key == 78)
		frac->scale -= frac->scale_step;
	if (frac->scale <= 0)
		frac->scale += frac->scale_step;
}

void	shift(t_frac *frac, int key)
{
	if (key == 65363 || key == 124)
		frac->shift_x -= 125;
	if (key == 65361 || key == 123)
		frac->shift_x += 125;
	if (key == 65362 || key == 126)
		frac->shift_y += 125;
	if (key == 65364 || key == 125)
		frac->shift_y -= 125;
}

void	change_iter(t_frac *frac, int key)
{
	if (key == 97 || key == 0)
		frac->num_of_iter++;
	else
		frac->num_of_iter--;
	if (frac->num_of_iter < 0)
		frac->num_of_iter = 0;
}
