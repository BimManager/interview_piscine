/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findShifted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:01:26 by kkozlov           #+#    #+#             */
/*   Updated: 2020/02/27 18:30:19 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	xbsrch(int *arr, int n, int value)
{
	int	lhs;
	int	rhs;
	int	mid;

	lhs = 0;
	rhs = n;
	while (lhs <= rhs)
	{
		mid = (lhs + rhs) / 2;
		if (mid && arr[mid - 1] == value)
			rhs = mid;
		else if (arr[mid] == value)
			return (mid);
		else if (arr[mid] > value)
			rhs = mid - 1;
		else
			lhs = mid + 1;
	}
	return (-1);
}

static int	pivotGet(int *rocks, int n)
{
	int	i;

	i = 0;
	while (++i < n)
		if (rocks[0] > rocks[i])
			return (i - 1);
	return (-1);
}

int	searchShifted(int *rocks, int length, int value)
{
	int	pivot;
	int	idx;
	
	if (rocks[0] == value)
		return (0);
	pivot = pivotGet(rocks, length);
	if (-1 != (idx = xbsrch(rocks, pivot, value)))
		return (idx);
	if (-1 != (idx = xbsrch(rocks + pivot, length - pivot, value)))
		return (pivot + idx);
	return (-1);
}
