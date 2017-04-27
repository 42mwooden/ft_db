
#ifndef FT_DB_H
# define FT_DB_H

# include "libft.h"
# include <fcntl.h>
# include <stdio.h>

/*
**	This struct is your ft_db instance.
*/
typedef struct	s_db
{
	char		*name;
	char		*buf;
}				t_db;

/*
**	To make a query declare a t_query and provide it your command, then call the
**	function query() providing it the target t_db. It will store the relevant
**	data in the t_query struct. Re-using a t_query is encouraged.
*/
typedef struct	s_query
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

typedef struct	s_field
{
	t_type		type;
	char		*name;
	void		*value;
}				t_field;

t_db			create_db(char *name);
int				db_exists(char *name);
t_db			get_db(char *name);
void			flush(t_db *db);

void			buf_append(char **big, char *small, int offset);
void			buf_clip(char **buf, int start, int end);

void			make(t_db *db, t_query *query, char **words);
void			query(t_db *db, t_query *query);

#endif
