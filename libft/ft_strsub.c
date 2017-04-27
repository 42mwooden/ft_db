/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 06:24:11 by mwooden           #+#    #+#             */
/*   Updated: 2016/11/07 17:34:16 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*out;

	i = 0;
	if (!s)
		return (NULL);
	if (!(out = (char *)malloc(len + 1)))
		return (NULL);
	while (i < len)
		out[i++] = s[start++];
	out[i] = '\0';
	return (out);
}
