/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotspots.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 12:37:55 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/04 14:15:49 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "header.h"

#include <stdio.h>

static int	hotspotcmp(const void *pv1, const void *pv2)
{
	struct s_hotspot *hs1;
	struct s_hotspot *hs2;

	hs1 = *(struct s_hotspot **)pv1;
	hs2 = *(struct s_hotspot **)pv2;
	if ((hs1->pos + hs1->radius) > (hs2->pos + hs2->radius))
		return (1);
	else if ((hs1->pos + hs1->radius) < (hs2->pos + hs2->radius))
		return (-1);
	return (0);
}

/*
** 1. Sort the hotspots according to their end range
**    that is computed by (pos + radius).
** 2. Increase the count if the current hotspot's
**    start range is greater than or equal to
**    the last selected hotspot's end range
** 3. Repeat until the end
*/

int			selectHotspots(struct s_hotspot **hotspots)
{
	int	start_range;
	int	end_range;
	int	keep;
	int	n;

	if (!hotspots || !*hotspots)
		return (0);
	n = 0;
	while (hotspots[++n])
		;
	qsort(hotspots, n, sizeof(void *), &hotspotcmp);
	start_range = (*hotspots)->pos - (*hotspots)->radius;
	end_range = (*hotspots)->pos + (*hotspots)->radius;
	keep = 1;
	while (*++hotspots)
	{
		if ((start_range = (*hotspots)->pos - (*hotspots)->radius) >= end_range)
		{
			++keep;
			end_range = (*hotspots)->pos + (*hotspots)->radius;
		}
	}
	return (keep);
}
