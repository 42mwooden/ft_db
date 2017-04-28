/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   query.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <mwooden@student.42.us>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 09:42:35 by mwooden           #+#    #+#             */
/*   Updated: 2017/04/27 09:42:38 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	analyze_query(t_db *db, t_query *query, char **words)
{
	if (ft_strequ(words[0], "MAKE"))
		make(db, query, words);
}

void	query(t_db *db, t_query *query)
{
	int		i;
	char	**words;

	words = ft_strsplit(query->command, ' ');
	analyze_query(db, query, words);
	free(query->command);
	i = -1;
	while (words[++i] != NULL)
		free(words[i]);
	free(words);
}
