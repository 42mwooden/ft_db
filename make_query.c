/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_query.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <mwooden@student.42.us>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 09:49:31 by mwooden           #+#    #+#             */
/*   Updated: 2017/04/27 09:49:50 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

static t_type	get_type(char **words, int *cur_p)
{
	t_type		out;

	out = F_UNDEF;
	if (ft_strequ(words[1], "INT"))
	{
		out = F_INT;
		(*cur_p)++;
	}
	else if (ft_strequ(words[1], "DOUBLE")) //not yet functional
	{
		out = F_DOUBLE;
		(*cur_p)++;
	}
	else if (ft_strequ(words[1], "STRING"))
	{
		out = F_STRING;
		(*cur_p)++;
	}
	if (ft_strequ(words[2], "ARRAY"))
	{
		out += 3;
		(*cur_p)++;
	}
	return (out);
}

static char		*get_name(char **words, int *cur_p)
{
	char	*name;
	int		i;

	name = words[*cur_p];
	(*cur_p)++;
	i = -1;
	while (name[++i])
	{
		if (i == 0 && !ft_isalpha(name[i]) && name[i] != '_')
			return (NULL);
		else if (!ft_isalnum(name[i]) && name[i] != '_')
			return (NULL);
	}
	return (name);
}

static int		check_error(t_query *query, int cond, char *error)
{
	if (cond)
	{
		query->success = 0;
		query->result = ft_strdup(error);
		return (0);
	}
	else
	{
		query->success = 1;
		return (1);
	}
}

static char		*get_val(t_field field, char **words, int *cur_p)
{
	char		*out;

	out = NULL;
	if (ft_strequ(words[*cur_p], "="))
		(*cur_p)++;
	if (field.type == F_INT)
		out = val_int(ft_atoi(words[*cur_p]));
	else if (field.type == F_STRING)
		out = val_str(words[*cur_p]);
	return (out);
}

void			make(t_db *db, t_query *query, char **words)
{
	int			cur;
	t_field		field;
	int			len;
	char		*buff;
	char*		val;

	cur = 1;
	field.type = get_type(words, &cur);
	if (!check_error(query, field.type == F_UNDEF, "Error: bad type"))
		return ;
	field.name = get_name(words, &cur);
	if (!check_error(query, field.name == NULL, "Error: bad name"))
		return ;
	else if (!check_error(query, name_exists(db, field), "Error: field exists"))
		return ;
	len = 4 + ft_strlen(field.name) + num_digits(ft_strlen(field.name));
	val = get_val(field, words, &cur);
	if (!check_error(query, val == NULL, "Error: bad value"))
		return ;
	len += ft_strlen(val) + 1;
	buff = ft_memalloc(len);
	sprintf(buff, "k:%d:%s,%s;", (int)ft_strlen(field.name), field.name, val);
	buff_append(&(db->buff), buff, 0);
}
