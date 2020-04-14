/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPrice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 10:52:33 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/03 11:11:05 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	xCalcTotal(int *arr, int n, double *prices, double *total)
{
	double	cur_total;
	int		i;

	cur_total = 0;
	i = -1;
	while (++i < n)
		cur_total += prices[arr[i]];
	if (cur_total > *total)
		*total = cur_total;
}

static void	xSlicesRecurse(int i, int n, int *arr, int idx,
							double *prices, double *total)
{
	int	j;

	if (!n)
		xCalcTotal(arr, idx, prices, total);
	j = i - 1;
	while (++j <= n)
	{
		arr[idx] = j;
		xSlicesRecurse(j, n - j, arr, idx + 1, prices, total);
	}
}

double		bestPrice(int pizzaSize, double *prices)
{
	int		*arr;
	double	total;

	total = 0;
	arr = malloc(pizzaSize * sizeof(int));
	xSlicesRecurse(1, pizzaSize, arr, 0, prices, &total);
	free(arr);
	return (total);
}
