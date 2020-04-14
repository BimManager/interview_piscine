/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   probaDistance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 09:28:30 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/04 11:49:12 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "header.h"

static void	xcomb_util(int *arr, int start, int end, int *temp,
							int r, int idx, t_data *data)
{
	int	i;

	if (idx == r)
	{
		++data->n_combs;
		if (abs(temp[0] - temp[1]) > data->dist)
			++data->n_gts;
		return ;
	}
	i = start - 1;
	while (++i <= end)
	{
		temp[idx] = arr[i];
		xcomb_util(arr, i + 1, end, temp, r, idx + 1, data);
	}
}

static void	xcomb(int *arr, int n, int r, t_data *data)
{
	int		*temp;

	temp = malloc(r * sizeof(int));
	xcomb_util(arr, 0, n - 1, temp, r, 0, data);
	free(temp);
}

double		probaDistance(int dist, int *locations, int n)
{
	t_data	data;

	data.n_gts = 0;
	data.n_combs = 0;
	data.dist = dist;
	xcomb(locations, n, 2, &data);
	return ((double)data.n_gts / data.n_combs);
}
