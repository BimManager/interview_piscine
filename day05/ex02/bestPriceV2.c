/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPriceV2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 11:12:28 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/03 12:25:21 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

#define XMAX(a, b) ((a) > (b) ? (a) : (b))

static double	memoizedBestPrices(int slices, double *prices, double *tab)
{
	int		i;
	int		j;

	if (!slices)
		return (0);
	i = 0;
	while (++i <= slices)
	{
		j = 0;
		while (++j <= i)
			tab[i] = XMAX(tab[i], prices[j] + tab[i - j]);
	}
	return (tab[slices]);
}

double			optimizedBestPrice(int pizzaSize, double *prices)
{
	double	*tab;
	double	max;

	tab = malloc((pizzaSize + 1) * sizeof(double));
	bzero(tab, (pizzaSize + 1) * sizeof(double));
	max = memoizedBestPrices(pizzaSize, prices, tab);
	free(tab);
	return (max);
}
