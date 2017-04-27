/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 20:23:45 by mwooden           #+#    #+#             */
/*   Updated: 2016/11/07 22:44:27 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		trunc;
	int		called;

	called = 0;
	trunc = 1000000000;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n == -2147483648)
		{
			ft_putchar_fd('2', fd);
			n %= 1000000000;
		}
		n *= -1;
	}
	while (trunc > 0)
	{
		if ((n / trunc) != 0 || called == 1 || (n == 0 && trunc == 1))
		{
			called = 1;
			ft_putchar_fd((n / trunc) + '0', fd);
		}
		n %= trunc;
		trunc /= 10;
	}
}
