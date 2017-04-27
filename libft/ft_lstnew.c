/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 14:42:03 by mwooden           #+#    #+#             */
/*   Updated: 2016/11/07 19:21:58 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*out;

	if (!(out = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(out->content = (void *)malloc(content_size)))
			return (NULL);
		ft_memcpy(out->content, content, content_size);
		out->content_size = content_size;
	}
	else
	{
		out->content = NULL;
		out->content_size = 0;
	}
	out->next = NULL;
	return (out);
}
