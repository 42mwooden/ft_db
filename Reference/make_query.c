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
	else if (ft_strequ(words[1], "DOUBLE")) // Not currently implemented
	{
		out = F_DOUBLE;
		(*cur_p)++;
	}
	else if (ft_strequ(words[1], "STRING"))
	{
		out = F_STRING;
		(*cur_p)++;
	}
	if (ft_strequ(words[2], "ARRAY")) // Not currently implemented
	{
		out += 3;
		(*cur_p)++;
	}
	return (out);
}

static char		*get_name(char **words, int *cur_p)
{
	char 		*name;
	int			i;

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

static int		num_digits(int a)
{
	int			out;

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

static char		*val_int(int val)
{
	char		*out;

	out = ft_memalloc(2 + num_digits(val));
	sprintf(out, "i:%d", val);
	return (out);
}

static char		*val_str(char *str)
{
	char		*out;
	int			len;

	len = ft_strlen(str);
	out = ft_memalloc(3 + len + num_digits(len));
	sprintf(out, "s:%d:%s", (int)ft_strlen(str) - 2, str);
	return (out);
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

static void		go_through_brackets(char *str, int *i)
{
	int			brackets;

	brackets = 1;
	while (brackets && str[++(*i)])
	{
		if (str[*i] == '{')
			brackets++;
		else if (str[*i] == '}')
			brackets--;
		else if (str[*i] == '\"')
			while (str[++(*i)] != '\"' && str[*i]);
	}
}

static int		name_exists(t_db *db, t_field field)
{
	char		*str;
	int			i;
	int			len;

	i = -1;
	while (db->buf[++i])
	{
		if (db->buf[i] == 'k')
		{
			len = ft_atoi(&(db->buf[i + 2]));
			if (len != (int)ft_strlen(field.name))
				continue ;
			i += 3 + num_digits(len);
			str = ft_strsub(db->buf, i, len);
			if (ft_strequ(str, field.name))
			{
				free(str);
				return (1);
			}
			free(str);
		}
		else if (db->buf[i] == '\"')
			while (db->buf[++i] != '\"' && db->buf[i]);
		else if (db->buf[i] == '{')
			go_through_brackets(db->buf, &i);
	}
	return (0);
}

void			make(t_db *db, t_query *query, char **words)
{
	int			cur;
	t_field		field;
	int			len;
	char		*buf;
	char		*val;

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
	buf = ft_memalloc(len);
	sprintf(buf, "k:%d:%s,%s;", (int)ft_strlen(field.name), field.name, val);
	buf_append(&(db->buf), buf, 0);
}
