/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 13:48:45 by kkozlov           #+#    #+#             */
/*   Updated: 2020/02/26 16:31:49 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "header.h"

#include <stdio.h>

static int		playcmp(struct s_player *p1, struct s_player *p2)
{
	if (p1->score > p2->score)
		return (1);
	else if (p1->score < p2->score)
		return (-1);
	return (0);
}

static void		xmerge(struct s_player **players, int lhs, int mid, int rhs)
{
	void	**lhs_temp;
	void	**rhs_temp;
	int		lhs_n;
	int		rhs_n;
	int		i;
	int		j;

	lhs_n = mid - lhs + 1;
	rhs_n = rhs - mid;
	lhs_temp = malloc(lhs_n * sizeof(void *));
	rhs_temp = malloc(rhs_n * sizeof(void *));
	i = -1;
	while (++i < lhs_n)
		lhs_temp[i] = players[lhs + i];
	i = -1;
	while (++i < rhs_n)
		rhs_temp[i] = players[mid + 1 + i];
	i = 0;
	j = 0;
	while (i < lhs_n && j < rhs_n)
	{
		if (playcmp(lhs_temp[i], rhs_temp[j]) >= 0)
		{
			players[lhs + i + j] = lhs_temp[i];
			++i;
		}
		else
		{
			players[lhs + i + j] = rhs_temp[j];
			++j;
		}
	}
	while (i < lhs_n)
	{
		players[lhs + i + j] = lhs_temp[i];
		++i;
	}
	while (j < rhs_n)
	{
		players[lhs + i + j] = rhs_temp[j];
		++j;
	}
	free(lhs_temp);
	free(rhs_temp);
}

static void		xmergesort(struct s_player **players, int lhs, int rhs)
{
	int	mid;

	if (lhs < rhs)
	{
		mid = (rhs + lhs) / 2;
		xmergesort(players, lhs, mid);
		xmergesort(players, mid + 1, rhs);
		xmerge(players, lhs, mid, rhs);
	}
}

struct s_player	**mergeSort(struct s_player **players)
{
	int	n;

	n = -1;
	while (players[++n])
		;
	xmergesort(players, 0, n - 1);
	return (players);
}
