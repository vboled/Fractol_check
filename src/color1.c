/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 18:50:27 by gweasley          #+#    #+#             */
/*   Updated: 2020/03/14 19:00:46 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			color2(int iter)
{
	if (!(iter % 7))
		return (0x800080);
	if (!(iter % 6))
		return (0x000080);
	if (!(iter % 5))
		return (0x0000FF);
	if (!(iter % 4))
		return (0x66FF00);
	if (!(iter % 3))
		return (0xFFFF00);
	if (!(iter % 2))
		return (0xFF8800);
	if (!(iter % 1))
		return (0xFF0000);
	return (0xFFFFFF);
}
