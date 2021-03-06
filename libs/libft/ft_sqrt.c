/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:18:57 by gweasley          #+#    #+#             */
/*   Updated: 2019/09/02 18:32:52 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int i;

	i = 1;
	while (i < nb / 2)
	{
		if ((nb / i) == i)
		{
			if (i * i == nb)
				return (i);
			else
				return (0);
		}
		i++;
	}
	return (0);
}
