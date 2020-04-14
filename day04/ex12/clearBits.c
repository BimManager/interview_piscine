/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearBits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 12:31:43 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/01 12:38:02 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			clearBits(unsigned int parkingRow, int n)
{
	int	all_ones;

	if (n <= 0)
		return (parkingRow);
	all_ones = 0xffffffff;
	while (n--)
		all_ones <<= 1;
	return (parkingRow & all_ones);
}
