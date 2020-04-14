/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correctSong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 08:52:03 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/02 10:25:55 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	correctSong(struct s_bit *bit, int l, int row, int col, int dist)
{
	int	*it;

	if ((0 >= l || 32 < l)
		|| (row + dist > bit->n)
		|| 0 > dist || 0 > l
		|| 0 > col || 0 > row)
		return ;
	it = (bit->arr + row);
	while (dist--)
	{
		*it = (1 << col);
		++it;
	}
}
