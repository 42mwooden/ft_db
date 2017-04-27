/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 20:30:03 by mwooden           #+#    #+#             */
/*   Updated: 2016/11/07 18:18:15 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*math_doer(int n, int trunc, int called, char *out)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		out[i++] = '-';
		if (n == -2147483648)
		{
			out[i++] = '2';
			n %= 1000000000;
		}
		n *= -1;
	}
	while (trunc > 0)
	{
		if ((n / trunc) != 0 || called == 1 || (n == 0 && trunc == 1))
		{
			called = 1;
			out[i++] = (n / trunc) + '0';
		}
		n %= trunc;
		trunc /= 10;
	}
	return (out);
}

char	*ft_itoa(int n)
{
	char	*out;
	int		i;
	int		places;

	i = n >= 0 ? n : -n;
	places = n >= 0 ? 1 : 2;
	while (i > 10)
	{
		i /= 10;
		places++;
	}
	if (n == -2147483648)
		places = 11;
	i = 0;
	if (!(out = (char *)malloc(places + 1)))
		return (NULL);
	while (i < places + 2)
		out[i++] = '\0';
	return (math_doer(n, 1000000000, 0, out));
}
