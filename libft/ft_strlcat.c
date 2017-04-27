/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 21:17:43 by mwooden           #+#    #+#             */
/*   Updated: 2016/10/11 17:50:30 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	i2;
	size_t	out;

	out = ft_strlen(dst) > size ? size + ft_strlen(src) :
		ft_strlen(dst) + (ft_strlen(src));
	i2 = 0;
	i = ft_strlen(dst);
	if (size == 0)
		return (out);
	while (i < size - 1)
		dst[i++] = src[i2++];
	dst[i] = '\0';
	return (out);
}
