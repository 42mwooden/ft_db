/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <mwooden@student.42.us>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 09:11:24 by mwooden           #+#    #+#             */
/*   Updated: 2017/04/27 09:11:29 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DB_H
# define FT_DB_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef	struct	s_db
{
	char		*name;
	char		*buff;
}				t_db;

typedef	struct	s_query
{
	char		*command;
	int			success;
	char		*result;
}				t_query;

typedef enum	e_type
{
	F_UNDEF,
	F_INT,
	F_DOUBLE,
	F_STRING,
	F_ARRAY_INT,
	F_ARRAY_DOUBLE,
	F_ARRAY_STRING
}				t_type;

typedef	struct	s_field
{
	t_type		type;
	char		*name;
	void		*value;
}				t_field;

t_db			create_db(char *name);
int				db_exists(char *name);
t_db			get_db(char *name);
void			flush(t_db *db);

void			buff_append(char **big, char *small, int offset);
void			buff_clip(char **buff, int start, int end);

void			make(t_db *db, t_query *query, char **words);
void			query(t_db *db, t_query *query);

/*
** make helper functions
*/

int				num_digits(int a);
char			*val_int(int val);
char			*val_str(char *str);
void			go_through_brackets(char *str, int *i);
int				name_exists(t_db *db, t_field field);

#endif
