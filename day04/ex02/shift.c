/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:24:05 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/02 09:24:28 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*rightShift(char *bin, int k)
{
	char	*it;

	it = bin;
	while (*it)
		++it;
	while (--it >= bin)
		*it = (it - k) <= bin ? *bin : *(it - k);
	return (bin);
}

char	*leftShift(char *bin, int k)
{
	char	*it;
	char	*end;

	it = bin;
	end = it;
	while (*end)
		++end;
	while (end - it > k)
	{
		*it = *(it + k);
		++it;
	}
	while (*it)
		*it++ = '0';
	return (bin);
}

int		toInt(char *bin)
{
	int		res;
	int		power;
	char	*it;

	res = 0;
	power = 0;
	it = bin;
	while (*it)
		++it;
	while (it > (bin + 1))
		res += (*--it - '0') << power++;
	if ('1' == *bin)
		res *= -1;
	return (res);
}
