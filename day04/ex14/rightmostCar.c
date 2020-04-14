/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rightmostCar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 12:50:44 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/01 12:52:51 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			rightmostCar(unsigned int parkingRow)
{
	int	pos;

	if (!parkingRow)
		return (-1);
	pos = 0;
	while (!(parkingRow & 1))
	{
		++pos;
		parkingRow >>= 1;
	}
	return (pos);
}
