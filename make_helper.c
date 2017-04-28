/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <mwooden@student.42.us>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 10:18:39 by mwooden           #+#    #+#             */
/*   Updated: 2017/04/27 10:18:41 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		num_digits(int a)
{
	int		out;

	out = 0;
	if (a == 0)
		return (1);
	if (a < 0)
	{
		out++;
		a *= -1;
	}
	while (a > 0)
	{
		out++;
		a /= 10;
	}
	return (out);
}

char	*val_int(int val)
{
	char	*out;

	out = ft_memalloc(2 + num_digits(val));
	sprintf(out, "i:%d", val);
	return (out);
}

char	*val_str(char *str)
{
	char	*out;
	int		len;

	len = ft_strlen(str);
	out = ft_memalloc(3 + len + num_digits(len));
	sprintf(out, "s:%d:%s", (int)ft_strlen(str) - 2, str);
	return (out);
}

void	go_through_brackets(char *str, int *i)
{
	int		brackets;

	brackets = 1;
	while (brackets && str[++(*i)])
	{
		if (str[*i] == '{')
			brackets++;
		else if (str[*i] == '}')
			brackets--;
		else if (str[*i] == '\"')
			while (str[++(*i)] != '\"' && str[*i])
				;
	}
}

int		name_exists(t_db *db, t_field field)
{
	char	*str;
	int		i;
	int		len;

	i = -1;
	while (db->buff[++i])
	{
		if (db->buff[i] == 'k')
		{
			len = ft_atoi(&(db->buff[i + 2]));
			if (len != (int)ft_strlen(field.name))
				continue ;
			i += 3 + num_digits(len);
			str = ft_strsub(db->buff, i, len);
			if (ft_strequ(str, field.name))
			{
				free(str);
				return (1);
			}
			free(str);
		}
		else if (db->buff[i] == '\"')
			while (db->buff[++i] != '\"' && db->buff[i]);
		else if (db->buff[i] == '{')
			go_through_brackets(db->buff, &i);
	}
	return (0);
}
