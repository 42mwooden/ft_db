/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 15:26:05 by mwooden           #+#    #+#             */
/*   Updated: 2016/11/07 22:59:02 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_power(int nb, int power)
{
	int i;
	int out;

	i = power;
	out = nb;
	if (i < 0)
		return (0);
	if (i == 0)
		return (1);
	while (i > 1)
	{
		out *= nb;
		i--;
	}
	return (out);
}
