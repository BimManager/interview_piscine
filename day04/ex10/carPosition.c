/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carPosition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 12:15:18 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/01 12:26:25 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	isPowerOfTwo(unsigned int x)
{
	return (x > 0 && (x & (x - 1)) == 0);
}

int			carPosition(unsigned int parkingRow)
{
	int	pos;

	if (!isPowerOfTwo(parkingRow))
		return (-1);
	pos = 0;
	while ((parkingRow >>= 1))
		++pos;
	return (pos);
}
