/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortStone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 08:54:38 by kkozlov           #+#    #+#             */
/*   Updated: 2020/02/27 11:53:59 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "header.h"

/*
**static void	intswap(int *a, int *b)
**{
**	*a ^= *b;
**	*b ^= *a;
**	*a ^= *b;
**}
**
**static void	xinsort(struct s_stone **head)
**{
**	char	is_sorted;
**	struct s_stone	*it;
**
** is_sorted = 0;
**	while (!is_sorted)
**	{
**		it = *head;
**		is_sorted = 1;
**		while (it->next)
**		{
**			if (it->size > it->next->size)
**			{
**				intswap(&it->size, &it->next->size);
**				is_sorted = 0;
**			}
**			it = it->next;
**		}
**	}
**}
**
**void		sortStones(struct s_stone **stone)
**{
**	xinsort(stone);
*}
*/

static int	lstlen(const struct s_stone *stones)
{
	int	len;

	len = 0;
	while (stones)
	{
		++len;
		stones = stones->next;
	}
	return (len);
}

static int	maxget(int *arr, int n)
{
	int	max;
	int	i;

	max = INT_MIN;
	i = -1;
	while (++i < n)
		if (arr[i] > max)
			max = arr[i];
	return (max);
}

static void	xoptimised_sort(int *arr, int n)
{
	int	max;
	int	i;
	int	*idx;
	int	*out;

	max = maxget(arr, n);
	idx = malloc(++max * sizeof(int));
	bzero(idx, max * sizeof(int));
	i = -1;
	while (++i < n)
		idx[arr[i]] += 1;
	i = 0;
	while (++i < max)
		idx[i] += idx[i - 1];
	out = malloc(n * sizeof(int));
	i = -1;
	while (++i < n)
	{
		out[idx[arr[i]] - 1] = arr[i];
		idx[arr[i]] -= 1;
	}
	i = -1;
	while (++i < n)
		arr[i] = out[i];
	free(idx);
	free(out);
}

void		sortStones(struct s_stone **stone)
{
	int				*arr;
	int				n_elems;
	int				i;
	struct s_stone	*it;

	n_elems = lstlen(*stone);
	arr = malloc(n_elems * sizeof(int));
	it = *stone;
	i = -1;
	while (++i < n_elems)
	{
		arr[i] = it->size;
		it = it->next;
	}
	xoptimised_sort(arr, n_elems);
	i = -1;
	it = *stone;
	while (++i < n_elems)
	{
		it->size = arr[i];
		it = it->next;
	}
	free(arr);
}
