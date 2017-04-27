/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 09:35:19 by mwooden           #+#    #+#             */
/*   Updated: 2016/11/07 18:36:38 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*out;
	int		i;

	i = 0;
	if (!(out = (char *)malloc(ft_strlen(s1) + 1)))
		return (NULL);
	while (s1[i] != '\0')
	{
		out[i] = s1[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}
