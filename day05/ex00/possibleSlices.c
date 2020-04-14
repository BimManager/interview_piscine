/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibleSlices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:07:08 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/03 08:48:15 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "header.h"

static void	xSlicesPrint(int *arr, int n)
{
	int	i;

	i = -1;
	printf("[");
	while (++i < n)
	{
		printf("%d", arr[i]);
		if (i != (n - 1))
			printf(", ");
	}
	printf("]\n");
}

static void	xSlicesRecurse(int i, int n, int *arr, int idx)
{
	int	j;

	if (!n)
		xSlicesPrint(arr, idx);
	j = i - 1;
	while (++j <= n)
	{
		arr[idx] = j;
		xSlicesRecurse(j, n - j, arr, idx + 1);
	}
}

void		printPossibleSlices(int pizzaSize)
{
	int	*arr;

	arr = malloc(pizzaSize * sizeof(int));
	xSlicesRecurse(1, pizzaSize, arr, 0);
	free(arr);
}
