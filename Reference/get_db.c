
#include "ft_db.h"

t_db		create_db(char *name)
{
	t_db	new_db;
	int		fd;

	new_db.name = ft_strdup(name);
	fd = open(name, O_RDWR | O_CREAT, 0644);
	ft_get_next_line(fd, &new_db.buf);
	close(fd);
	return (new_db);
}

int			db_exists(char *name)
{
	int		ret;

	ret = access(name, R_OK | W_OK);
	if (ret == 0)
		return (1);
	else
		return (0);
}

t_db		get_db(char *name)
{
	t_db	target;
	int		fd;

	if (!db_exists(name))
		return (create_db(name));
	target.name = ft_strdup(name);
	fd = open(name, O_RDWR, 0644);
	ft_get_next_line(fd, &target.buf);
	close(fd);
	return (target);
}
