/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 23:24:15 by mwooden           #+#    #+#             */
/*   Updated: 2016/11/07 22:46:22 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define WHITE(x) (x == ' ' || x == '\t' || x == '\n')

char	*snipsnip(const char *s, int trim, int i, int i2)
{
	char	*out;
	int		len;

	len = ft_strlen(s);
	if (len - trim < 1)
		out = (char *)malloc(1);
	else
		out = (char *)malloc(len - trim + 1);
	if (!out)
		return (NULL);
	while (WHITE(s[i]))
		i++;
	if (s[i] == '\0')
	{
		out[0] = '\0';
		return ((char *)&out[0]);
	}
	trim -= i;
	while (s[i] != '\0' && i < len - trim)
		out[i2++] = s[i++];
	out[i2] = '\0';
	return (out);
}

char	*ft_strtrim(const char *s)
{
	int		trim;
	int		i;
	int		call;

	call = 0;
	i = 0;
	trim = 0;
	while (s[i] != '\0')
	{
		call = WHITE(s[i]) ? call : call + 1;
		trim = call == 0 ? trim + 1 : trim;
		i++;
	}
	i--;
	while (WHITE(s[i]))
	{
		i--;
		trim++;
	}
	if (trim == 0)
		return ((char *)s);
	return (snipsnip(s, trim, 0, 0));
}
