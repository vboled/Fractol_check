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

int		add_frac(t_frac **frac, int type)
{
	t_frac	*tmp;

	if (!(*frac))
	{
		if (!(*frac = (t_frac *)malloc(sizeof(t_frac))))
			return (0);
		frac_init(*frac, type, NULL);
		(*frac)->head = *frac;
		return (1);
	}
	tmp = *frac;
	while ((*frac)->next)
		*frac = (*frac)->next;
	if (!((*frac)->next = (t_frac *)malloc(sizeof(t_frac))))
		return (0);
	frac_init((*frac)->next, type, (*frac)->mlx);
	(*frac)->next->head = (*frac)->head;
	*frac = tmp;
	return (1);
}

void	init(t_frac *frac, int type)
{
	frac->type = type;
	frac->next = NULL;
	frac->shift_x = 0;
	frac->shift_y = 0;
	frac->mouse_x = 400;
	frac->mouse_y = 500;
	frac->num_of_iter = 10;
	frac->scale_step = 5;
	frac->num_of_str = 1;
	frac->color_scheme = 0;
	frac->scale = 100;
	frac->c_x = -0.8;
	frac->c_y = 0.156;
	frac->z_change = 0;
	frac->num_of_dragon = 1;
}

void	frac_init(t_frac *frac, int type, void *mlx)
{
	init(frac, type);
	if (mlx)
		frac->mlx = mlx;
	else
		frac->mlx = mlx_init();
	frac->win = mlx_new_window(frac->mlx, WIDTH + 405, WIDTH + 100, "win1");
	frac->img = mlx_new_image(frac->mlx, WIDTH, WIDTH);
}

void	create_mlx_image(t_frac *frac)
{
	frac->num_of_str = 1;
	frac->pix_m = (int *)mlx_get_data_addr(frac->img,
	&(frac->bits_per_pixel), &(frac->size_line), &(frac->endian));
	clear_window(frac);
	mlx_clear_window(frac->mlx, frac->win);
	mlx_string_put(frac->mlx, frac->win, 30, 30 * frac->num_of_str++,
	0xFFFFFF, "For change name of iter press A or Z");
	mlx_string_put(frac->mlx, frac->win, 30, 30 * frac->num_of_str++, 0xFFFFFF,
	"Use arrows for shifting fractal");
	mlx_string_put(frac->mlx, frac->win, 30, 30 * frac->num_of_str++, 0xFFFFFF,
	"For change color press W");
	mlx_string_put(frac->mlx, frac->win, 30, 30 * frac->num_of_str++, 0xFFFFFF,
	"For zoom press +/-");
	call_fractal(frac);
	mlx_put_image_to_window(frac->mlx, frac->win, frac->img, 400, 50);
}
