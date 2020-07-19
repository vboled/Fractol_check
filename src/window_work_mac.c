/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:29:08 by gweasley          #+#    #+#             */
/*   Updated: 2020/05/12 22:09:34 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		deal_hook(int key, t_frac *param)
{
	if (key == 53)
		destroy_window(param);
	if (param->type != -1)
	{
		if (key == 49)
			change_flag(param);
		if (key == 5 || key == 11)
			change_dragon(param, key);
		if (key >= 123 && key <= 126)
			shift(param, key);
		if (key == 69 || key == 78)
			scale_key(param, key);
		if (key == 0 || key == 6)
			change_iter(param, key);
		if (key == 13)
			change_color(param);
		create_mlx_image(param);
	}
	return (0);
}
