/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leftmostCar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 12:38:59 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/01 12:46:51 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			leftmostCar(unsigned int parkingRow)
{
	int	pos;

	if (!parkingRow)
		return (-1);
	pos = 0;
	while ((parkingRow >>= 1))
		++pos;
	return (pos);
}
