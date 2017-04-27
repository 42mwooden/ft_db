/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 21:04:55 by mwooden           #+#    #+#             */
/*   Updated: 2016/10/17 12:09:04 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	i2;
	size_t	it;

	i = 0;
	i2 = 0;
	it = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		if (big[i] == little[0])
		{
			it = i;
			i2 = 0;
			while ((little[i2] == big[it] && big[it] != '\0') && it < len)
			{
				if (little[++i2] == '\0')
					return ((char *)&big[i]);
				it++;
			}
		}
		i++;
	}
	return (0);
}
