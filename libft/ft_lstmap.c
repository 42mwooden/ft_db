/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 22:48:49 by mwooden           #+#    #+#             */
/*   Updated: 2016/10/06 23:20:14 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*out;

	if (!lst)
		return (NULL);
	out = (t_list *)malloc(sizeof(t_list));
	if (!out)
		return (NULL);
	out = f(lst);
	if (!out)
		return (NULL);
	if (lst->next)
		out->next = ft_lstmap(lst->next, f);
	else
		out->next = NULL;
	return (out);
}
