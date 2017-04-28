/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flush.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <mwooden@student.42.us>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 11:57:44 by mwooden           #+#    #+#             */
/*   Updated: 2017/04/27 11:57:46 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	flush(t_db *db)
{
	int		fd;

	fd = open(db->name, O_RDWR | O_TRUNC, 0644);
	write(fd, db->buff, ft_strlen(db->buff));
	close(fd);
}
