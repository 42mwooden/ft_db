/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 00:00:32 by mwooden           #+#    #+#             */
/*   Updated: 2016/10/07 00:16:07 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		len;
	int		i;
	int		i2;
	char	*out;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	i2 = 0;
	out = (char *)malloc(len + 1);
	if (out == NULL)
		return (NULL);
	while (s1[i2] != '\0')
		out[i++] = s1[i2++];
	i2 = 0;
	while (s2[i2] != '\0')
		out[i++] = s2[i2++];
	out[i] = '\0';
	return (out);
}
