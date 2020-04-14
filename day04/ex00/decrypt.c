/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrypt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 10:53:32 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/02 09:12:55 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*getSum(char *a, char *b)
{
	char	carry;
	char	sum;
	char	*a_it;
	char	*b_it;

	a_it = a;
	b_it = b;
	while (*a_it)
		++a_it;
	while (*b_it)
		++b_it;
	carry = 0;
	while (--a_it >= a && --b_it >= b)
	{
		sum = (*a_it + *b_it + carry) % 4;
		*a_it = sum % 2 + '0';
		carry = (sum - (sum % 2)) > 0 ? 1 : 0;
	}
	return (a);
}

int		toInt(char *bits)
{
	int		res;
	int		power;
	char	*it;

	res = 0;
	power = 0;
	it = bits;
	while (*it)
		++it;
	while (it > bits)
		res += (*--it - '0') << power++;
	return (res);
}
