/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 16:16:56 by mwooden           #+#    #+#             */
/*   Updated: 2016/09/25 20:58:50 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;
	int				ret;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	ret = 0;
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	while (str1[i] == str2[i] && str1[i] != '\0')
		i++;
	if (str1[i] != str2[i])
		ret = str1[i] - str2[i];
	return (ret);
}
