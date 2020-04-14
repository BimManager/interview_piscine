/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setPlace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 08:44:19 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/01 08:45:05 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	setPlace(unsigned int parkingRow, int pos)
{
	return (parkingRow | (1 << pos));
}
