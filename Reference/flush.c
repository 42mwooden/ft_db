
#include "ft_db.h"

void		flush(t_db *db)
{
	int		fd;

	fd = open(db->name, O_RDWR | O_TRUNC, 0644);
	write(fd, db->buf, ft_strlen(db->buf));
	close(fd);
}
