/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionSort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 11:54:07 by kkozlov           #+#    #+#             */
/*   Updated: 2020/02/26 13:43:14 by kkozlov          ###   ########.fr       */
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

void		insertionSort(struct s_player **players)
{
	int	i;
	int	j;

	i = 0;
	while (players[++i])
	{
		j = i;
		while (0 < j && 0 > playcmp(players[j - 1], players[j]))
		{
			memswap(players + j - 1, players + j, sizeof(void *));
			--j;
		}
	}
}
