/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makeThemEat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 13:33:44 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/03 15:07:19 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "header.h"

static void	xpossible(struct s_people **people, int *times, int n, int *res)
{
	int	i;

	if (!*people)
		return ;
	i = -1;
	while (++i < n)
	{
		if (times[i] >= (*people)->time)
		{
			times[i] -= (*people)->time;
			break ;
		}
		else if (i == n - 1)
			*res = 0;
	}
	if (*res)
		xpossible(people + 1, times, n, res);
}

int			isPossible(struct s_people **people, int nbTable, int totalTime)
{
	int	*times;
	int	i;
	int	res;

	res = 1;
	times = malloc(nbTable * sizeof(int));
	i = -1;
	while (++i < nbTable)
		times[i] = totalTime;
	xpossible(people, times, nbTable, &res);
	free(times);
	return (res);
}
