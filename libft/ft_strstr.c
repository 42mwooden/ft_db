/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 14:58:36 by mwooden           #+#    #+#             */
/*   Updated: 2016/09/28 18:17:22 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	itemp;
	char	*out;

	i = 0;
	itemp = 0;
	out = little[0] == '\0' ? (char *)big : 0;
	while (big[i] != '\0' && little[0] != '\0')
	{
		if (big[i] == little[0])
		{
			itemp = i;
			while (little[itemp - i] == big[itemp] && big[itemp] != '\0')
			{
				if (little[1 + (itemp++ - i)] == '\0')
				{
					out = (char *)&big[i];
					return (out);
				}
			}
		}
		i++;
	}
	return (out);
}
