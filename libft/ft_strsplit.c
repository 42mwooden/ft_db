/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 21:05:16 by mwooden           #+#    #+#             */
/*   Updated: 2016/11/07 17:25:53 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**copier(const char *s, char **out, char c, int segs)
{
	int		i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	while (s[i[0]] != '\0' && i[1] < segs)
	{
		if (s[i[0]] != c)
			out[i[1]][(i[2])++] = s[i[0]];
		else if (s[i[0]] == c && s[(i[0] + 1)] != c && (i[1] != 0 || i[2] != 0))
		{
			out[(i[1])++][i[2]] = '\0';
			i[2] = 0;
		}
		out[i[1]][i[2]] = '\0';
		i[0] += 1;
	}
	out[segs] = 0;
	return (out);
}

char	**splitter(const char *s, int segs, char c, int i)
{
	char	**out;
	int		temp;
	int		biggest;

	temp = 0;
	biggest = 0;
	if (!(out = (char **)malloc(sizeof(char *) * (segs + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] != c && s[++i] != '\0')
			temp++;
		i = temp == 0 ? i + 1 : i;
		biggest = temp > biggest ? temp : biggest;
		temp = 0;
	}
	while (temp <= segs)
		if (!(out[temp++] = (char *)malloc(biggest + 1)))
			return (NULL);
	if (!(out[temp] = (char *)malloc(1)))
		return (NULL);
	return (copier(s, out, c, segs));
}

char	**ft_strsplit(const char *s, char c)
{
	int		i;
	char	**out;
	int		segs;

	i = 0;
	segs = 1;
	if (!(out = (char **)malloc(sizeof(char *))))
		return (NULL);
	out[0] = NULL;
	if (!s)
		return (out);
	if (!s[0])
		return (out);
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i + 1] == c)
			segs++;
		i++;
	}
	segs = s[i - 1] == c ? segs - 1 : segs;
	out = splitter(s, segs, c, 0);
	return (out);
}
