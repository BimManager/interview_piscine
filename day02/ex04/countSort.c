/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:38:56 by kkozlov           #+#    #+#             */
/*   Updated: 2020/02/26 17:01:49 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

#include "header.h"

static unsigned char	maxget(unsigned char *arr, int n)
{
	int				i;
	unsigned char	max;

	max = 0;
	i = -1;
	while (++i < n)
		if (arr[i] > max)
			max = arr[i];
	return (max);
}

static void				xcounting_sort(unsigned char *arr, int n)
{
	unsigned char	max;
	int				*idx;
	unsigned char	*out;
	int				i;

	max = maxget(arr, n);
	idx = malloc(++max * sizeof(int));
	bzero(idx, max * sizeof(int));
	i = -1;
	while (++i < n)
		idx[arr[i]] += 1;
	i = 0;
	while (++i < max)
		idx[i] = idx[i] + idx[i - 1];
	out = malloc(n * sizeof(unsigned char));
	i = -1;
	while (++i < n)
	{
		out[idx[arr[i]] - 1] = arr[i];
		idx[arr[i]] -= 1;
	}
	i = -1;
	while (++i < n)
		arr[i] = out[i];
	free(out);
	free(idx);
}

void					countSort(unsigned char *utensils, int n)
{
	xcounting_sort(utensils, n);
}
