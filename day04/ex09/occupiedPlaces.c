/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   occupiedPlaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 09:15:35 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/01 12:14:33 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The population count algorithm
** O(log(32)) = 5 steps
** It uses the divide and
** conquer approach
*/

static int	popcount32(unsigned int x)
{
	x = x - ((x >> 1) & 0x55555555);
	x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
	x = (x + (x >> 4)) & 0x0f0f0f0f;
	x = x + (x >> 8);
	x = x + (x >> 16);
	return (x & 0x0000003f);
}

int			occupiedPlaces(unsigned int parkingRow)
{
	return (popcount32(parkingRow));
}
