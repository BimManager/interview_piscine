/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longestSequence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 12:54:14 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/02 10:21:30 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** It runs in O(4s + 3) instructions, where
** s is the length of the longest string of 1's
*/

int			longestSequence(unsigned int parkingRow)
{
	int	k;

	k = 0;
	while (parkingRow && ++k)
		parkingRow = parkingRow & (parkingRow << 1);
	return (k);
}
