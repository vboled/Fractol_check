/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_work.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 14:02:41 by gweasley          #+#    #+#             */
/*   Updated: 2020/03/08 14:02:42 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	change_z(int x, int y, t_frac *frac)
{
	if (frac->type != 2 || !frac->z_change)
		return ;
	if (x >= 400 && x <= 1200 && y >= 50 && y <= 850)
	{
		if (frac->old_x != -100)
		{
			if (x > frac->old_x)
				frac->c_x += 0.01;
			else if (x < frac->old_x)
				frac->c_x -= 0.01;
			if (y > frac->old_y)
				frac->c_y += 0.01;
			else if (y < frac->old_y)
				frac->c_y -= 0.01;
		}
		frac->old_x = x;
		frac->old_y = y;
		return ;
	}
}

int		mouse_motion(int x, int y, void *frac)
{
	change_z(x, y, frac);
	create_mlx_image(frac);
	return (0);
}

int		mouse_hook(int key, int x, int y, void *param)
{
	if (key == 4 || key == 5)
		mouse_wheel(param, key, x, y);
	create_mlx_image(param);
	return (0);
}

void	destroy_window(t_frac *frac)
{
	t_frac	*tmp;

	frac->type = -1;
	tmp = frac->head;
	while (tmp)
	{
		if (tmp->type != -1)
		{
			mlx_destroy_window(frac->mlx, frac->win);
			return ;
		}
		tmp = tmp->next;
	}
	write(1, "EXIT\n", 5);
	exit(0);
}

void	change_flag(t_frac *frac)
{
	if (!frac->z_change)
	{
		frac->old_x = -100;
		frac->z_change = 1;
	}
	else
		frac->z_change = 0;
}
