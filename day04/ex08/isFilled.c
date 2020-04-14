/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isFilled.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 09:00:45 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/02 10:00:32 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	isPowerOfTwo(unsigned int x)
{
	return (x > 0 && (x & (x - 1)) == 0);
}

int			isFilled(unsigned int parkingRow)
{
	return (isPowerOfTwo(parkingRow + 1));
}
