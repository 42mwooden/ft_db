/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 08:03:57 by mwooden           #+#    #+#             */
/*   Updated: 2016/09/29 09:26:01 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	char		*cdst;
	const char	*csrc;

	cdst = dst;
	csrc = src;
	i = 0;
	while (i < n)
	{
		cdst[i] = csrc[i];
		if (cdst[i] == c)
			return (&dst[i + 1]);
		i++;
	}
	return (NULL);
}
