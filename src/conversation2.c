/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversation2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 17:23:36 by gweasley          #+#    #+#             */
/*   Updated: 2020/03/08 17:23:38 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	change_dragon(t_frac *frac, int key)
{
	if (key == 103 || key == 5)
		frac->num_of_dragon += 1;
	else
		frac->num_of_dragon -= 1;
	if (frac->num_of_dragon < 1)
		frac->num_of_dragon = 1;
	if (frac->num_of_dragon > 4)
		frac->num_of_dragon = 4;
}

void	change_color(t_frac *frac)
{
	frac->color_scheme++;
	if (frac->color_scheme > 3)
		frac->color_scheme = 0;
}
