/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 13:09:02 by mwooden           #+#    #+#             */
/*   Updated: 2017/01/07 23:54:47 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		getter(t_line *start, char **line, int fd)
{
	t_line	*cur;

	cur = start;
	while (cur)
	{
		if (cur->fd == fd && cur->red == 0)
		{
			line[0] = cur->line;
			cur->red = 1;
			return (1);
		}
		cur = cur->next;
	}
	return (0);
}

t_line	*add(int fd, int len, char *line, char *start)
{
	t_line	*new;

	line = (char *)malloc(len + 1);
	ft_memcpy(line, start, len);
	line[len] = '\0';
	new = (t_line *)malloc(sizeof(t_line));
	new->fd = fd;
	new->red = 0;
	new->line = line;
	new->next = NULL;
	return (new);
}

void	new_file(t_line **start, char *file, int fd)
{
	char	*end;
	char	*prev;
	t_line	*link;
	t_line	*cur;

	cur = *start;
	prev = file;
	while (prev - 1 != 0)
	{
		end = ft_strchr(prev, 10);
		if (end)
			link = add(fd, end - prev, NULL, prev);
		else if (prev[0] != '\0')
			link = add(fd, ft_strlen(prev), NULL, prev);
		else
			link = NULL;
		if (cur)
			cur->next = link;
		else
			*start = link;
		cur = link == NULL ? cur : link;
		prev = end + 1;
	}
}

int		reader(char **ret, const int fd, int red, int i)
{
	char	*buff;
	char	*file;
	int		temp;

	if (!(buff = (char *)malloc(BUFF_SIZE)))
		return (-1);
	if (!(file = (char *)malloc(BUFF_SIZE)))
		return (-1);
	while (i == red)
	{
		temp = read(fd, buff, BUFF_SIZE);
		if (temp == -1)
			return (-1);
		red += temp;
		if (red == i + BUFF_SIZE)
			file = (char *)my_realloc(file, red + BUFF_SIZE, BUFF_SIZE);
		ft_memcpy(&file[i], buff, red - i);
		i += BUFF_SIZE;
	}
	file[red] = '\0';
	*ret = file;
	free(buff);
	return (red);
}

int		get_next_line(const int fd, char **line)
{
	static t_line	*begin = NULL;
	char			*file;
	int				bytes;
	t_line			*cur;

	cur = begin;
	if (cur)
		while (cur->next)
		{
			if (cur->fd == fd)
				return (getter(cur, line, fd));
			cur = cur->next;
		}
	bytes = reader(&file, fd, 0, 0);
	if (bytes == -1)
		return (-1);
	new_file(&cur, file, fd);
	free(file);
	if (!begin)
		begin = cur;
	return (getter(begin, line, fd));
}
