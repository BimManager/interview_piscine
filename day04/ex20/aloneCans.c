/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aloneCans.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 10:55:59 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/02 11:55:22 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
** xy_xor = x ^ y
** We know that one bit is set in x
** and unset in y, so by grabbing
** any bit and checking against it
** all the numbers in the array
** we break up the array into two
** sets, which in the end contain
** our unique numbers
*/

void	aloneCans(int *arr, int n)
{
	int	i;
	int	xy_xor;
	int	set_bit;
	int	set_x;
	int	set_y;

	i = -1;
	xy_xor = 0;
	while (++i < n)
		xy_xor ^= arr[i];
	set_bit = xy_xor & ~(xy_xor - 1);
	set_x = 0;
	set_y = 0;
	i = -1;
	while (++i < n)
	{
		if (set_bit & arr[i])
			set_x ^= arr[i];
		else
			set_y ^= arr[i];
	}
	printf("%d\n", set_x);
	printf("%d\n", set_y);
}
