/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 12:39:27 by kkozlov           #+#    #+#             */
/*   Updated: 2020/02/26 13:46:54 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "header.h"

static void	memswap(void *pv1, void *pv2, size_t n)
{
	char	temp;

	while (n--)
	{
		temp = *((char *)pv1 + n);
		*((char *)pv1 + n) = *((char *)pv2 + n);
		*((char *)pv2 + n) = temp;
	}
}

static int	playcmp(struct s_player *p1, struct s_player *p2)
{
	if (p1->score > p2->score)
		return (1);
	else if (p1->score < p2->score)
		return (-1);
	return (0);
}

static void	xqsort(struct s_player **players, int n)
{
	int	pivot;
	int	i;
	int	last;

	if (1 >= n)
		return ;
	pivot = 0;
	i = 0;
	last = 0;
	while (++i < n)
	{
		if (0 > playcmp(players[pivot], players[i]))
		{
			++last;
			memswap(players + i, players + last, sizeof(void *));
		}
	}
	memswap(players + pivot, players + last, sizeof(void *));
	xqsort(players, last);
	xqsort(players + last + 1, n - last - 1);
}

void		quickSort(struct s_player **players)
{
	int	n;

	n = -1;
	while (players[++n])
		;
	xqsort(players, n);
}
