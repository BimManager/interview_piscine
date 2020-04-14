/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotspots2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 11:48:53 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/11 12:17:52 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdio.h>

int selectHotspots(struct s_hotspot **hotspots)
{
	int					n_spots;
	struct s_hotspot	**curr;
	struct s_hotspot	**next;

	n_spots = 0;
	curr = hotspots;
	while (*curr++)
		++n_spots;
	printf("n_spots: %d\n", n_spots);
	curr = hotspots;
	next = curr + 1;
	while (*next)
	{
		if ((*curr)->pos + (*curr)->radius <= (*next)->pos - (*next)->radius)
		{
			curr = next;
			next += 1;
			continue ;
		}
		--n_spots;
		if ((*curr)->radius > (*next)->radius)
			curr = next;
		next += 1;
	}
	return (n_spots);
}
