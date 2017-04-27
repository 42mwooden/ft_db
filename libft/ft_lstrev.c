/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 22:32:34 by mwooden           #+#    #+#             */
/*   Updated: 2016/11/07 22:41:23 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		**ft_lstrev(t_list **begin)
{
	t_list	*prev;
	t_list	*next;
	t_list	*cur;

	prev = (*begin);
	cur = prev->next;
	next = cur->next;
	prev->next = NULL;
	while (cur)
	{
		cur->next = prev;
		prev = cur;
		cur = next;
		if (cur)
			next = cur->next;
	}
	*begin = prev;
	return (begin);
}
