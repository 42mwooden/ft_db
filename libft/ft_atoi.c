/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 11:34:58 by mwooden           #+#    #+#             */
/*   Updated: 2016/09/25 21:02:52 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define SPECIAL(x) (x==' '||x=='\n'||x=='\t'||x=='\v'||x=='\f'||x=='\r')

int		ft_atoi(char *str)
{
	int					i;
	unsigned long long	out;
	int					neg;
	int					i2;

	i = 0;
	out = 0;
	neg = 1;
	while (SPECIAL(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		neg = str[i++] == '-' ? -1 : 1;
	}
	i2 = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (out * neg);
		out = out * 10 + (str[i++] - 48);
		i2++;
	}
	if (i2 > 19 || out >= 9223372036854775808ull)
		return (neg == 1 ? -1 : 0);
	return (out * neg);
}
