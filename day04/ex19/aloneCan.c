/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aloneCan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 10:36:41 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/02 10:52:45 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	aloneCan(int *arr, int n)
{
	int	i;
	int	res;

	i = -1;
	res = 0;
	while (++i < n)
		res ^= arr[i];
	printf("%d\n", res);
}
