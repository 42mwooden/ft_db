/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_primefact.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 21:19:43 by mwooden           #+#    #+#             */
/*   Updated: 2016/11/07 22:47:53 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		makearray(int num, int **tab)
{
	int		i;
	int		count;
	int		*arr;

	count = 0;
	i = 2;
	while (!(ft_isprime(num)))
	{
		if (ft_isprime(i))
		{
			if (num % i == 0)
			{
				num /= i;
				i = 1;
				count++;
			}
		}
		i++;
	}
	if (!(arr = (int *)malloc(sizeof(int) * (count + 1))))
		return (0);
	*tab = arr;
	return (count + 1);
}

int		ft_primefact(int num, int **tab)
{
	int		i;
	int		index;
	int		count;

	index = 0;
	i = 2;
	count = makearray(num, tab);
	if (count == 0)
		return (0);
	while (!(ft_isprime(num)))
	{
		if (ft_isprime(i))
		{
			if (num % i == 0)
			{
				(*tab)[index++] = i;
				num /= i;
				i = 1;
			}
		}
		i++;
	}
	(*tab)[index] = num;
	return (count);
}
