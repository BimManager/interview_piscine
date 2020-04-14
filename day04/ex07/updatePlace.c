/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updatePlace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 08:47:16 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/02 09:58:20 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	updatePlace(unsigned int parkingRow, int pos, int value)
{
	if (1 < value || 0 > value)
		return (parkingRow);
	if (value)
		return (parkingRow | (1 << pos));
	return (parkingRow & ~(1 << pos));
}
