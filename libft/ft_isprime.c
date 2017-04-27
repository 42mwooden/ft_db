/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 13:18:13 by mwooden           #+#    #+#             */
/*   Updated: 2016/11/07 23:00:17 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprime(int nb)
{
	int i;
	int max;

	i = 7;
	max = nb / 7;
	if (nb <= 1)
		return (0);
	if (nb % 2 == 0 && nb != 2)
		return (0);
	if (nb % 3 == 0 && nb != 3)
		return (0);
	if (nb % 5 == 0 && nb != 5)
		return (0);
	if (nb % 7 == 0 && nb != 7)
		return (0);
	while (i < max)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}
