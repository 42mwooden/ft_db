
#include "ft_db.h"

void		buf_append(char **big, char *small, int offset)
{
	char	*tmp;
	char	*aid;

	if (offset == 0)
	{
		tmp = ft_strjoin(*big, small);
		free(*big);
		*big = tmp;
		return ;
	}
	aid = ft_strsub(*big, offset, ft_strlen(*big) - offset);
	tmp = ft_strjoin(small, aid);
	free(aid);
	aid = ft_strjoin(*big, tmp);
	free(*big);
	free(tmp);
	*big = aid;
}

void		buf_clip(char **buf, int start, int end)
{
	char	*head;
	char	*tail;

	if (start == end || start > end || start < 0)
		return ;
	head = ft_strsub(*buf, 0, start);
	tail = ft_strsub(*buf, end, ft_strlen(*buf) - end);
	free(*buf);
	*buf = ft_strjoin(head, tail);
	free(head);
	free(tail);
}
