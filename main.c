/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <mwooden@student.42.us>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 12:14:51 by mwooden           #+#    #+#             */
/*   Updated: 2017/04/27 12:14:53 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		main(void)
{
	t_db		*db;
	t_query		*qry;

	db = ft_memalloc(sizeof(t_db));
	db->name = "Test.txt";
	db->buff = ft_memalloc(20);
	qry = ft_memalloc(sizeof(t_query));
	qry->command = ft_strdup("MAKE STRING dbname = \"Test\"");
	qry->success = 0;
	qry->result = NULL;
	query(db, qry);
	flush(db);
	qry->command = ft_strdup("MAKE STRING test2 = \"test2\"");
	query(db, qry);
	flush(db);
	qry->command = ft_strdup("MAKE INT testnum = 36");
	query(db, qry);
	flush(db);
	return (0);
}
