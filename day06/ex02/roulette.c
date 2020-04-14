/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roulette.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:47:10 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/04 18:19:50 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static void	xprobability(double curr_amount, int wanted_amount,
				int n_games, double probability, double *result)
{
	if (!n_games)
		return ;
	if (curr_amount >= wanted_amount)
	{
		*result += probability;
		return ;
	}
	xprobability(curr_amount * 2, wanted_amount, n_games - 1,
				probability * 18.0 / 37, result);
	xprobability(curr_amount / 2, wanted_amount, n_games - 1,
				probability * 1.0 / 37, result);
}

double		probabilityWin(double initDollars, double wantedDollars, int nbGame)
{
	double	result;

	result = 0;
	xprobability(initDollars, wantedDollars, nbGame + 1, 1.0, &result);
	return (result);
}
