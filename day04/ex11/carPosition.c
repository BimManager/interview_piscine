/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carPosition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 12:15:18 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/01 12:29:59 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

static int	isPowerOfTwo(unsigned int x)
{
	return (x > 0 && (x & (x - 1)) == 0);
}

int			carPosition(unsigned int parkingRow)
{
	if (!isPowerOfTwo(parkingRow))
		return (-1);
	return (log2(parkingRow));
}
