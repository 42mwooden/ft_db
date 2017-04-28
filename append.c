/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <mwooden@student.42.us>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 12:00:19 by mwooden           #+#    #+#             */
/*   Updated: 2017/04/27 12:00:20 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	buff_append(char **big, char *small, int offset)
{
	char	*tmp;
	char	*aid;

	if (offset == 0)
	{
		tmp = ft_strjoin(*big, small);
		free(*big);
		*big = tmp;
		return;
	}
	aid = ft_strsub(*big, offset, ft_strlen(*big) - offset);
	tmp = ft_strjoin(small, aid);
	free(aid);
	aid = ft_strjoin(*big, tmp);
	free(*big);
	free(tmp);
	*big = aid;
}

void	buff_clip(char **buff, int start, int end)
{
	char	*head;
	char	*tail;

	if (start == end || start > end || start < 0)
		return ;
	head = ft_strsub(*buff, 0, start);
	tail = ft_strsub(*buff, end, ft_strlen(*buff) - end);
	free(*buff);
	*buff = ft_strjoin(head, tail);
	free(head);
	free(tail);
}
