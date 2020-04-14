/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:15:26 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/02 09:28:06 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	getComplement(char *a)
{
	if ('~' == *a)
		while (*++a)
			*(a - 1) = (*a + 1) % 2 + '0';
	*(a - 1) = '\0';
}

static void	getReady(char *a, char *b, char **a_it, char **b_it)
{
	getComplement(a);
	getComplement(b);
	*a_it = a;
	*b_it = b;
	while (**a_it)
		++*a_it;
	while (**b_it)
		++*b_it;
}

char		*getXor(char *a, char *b)
{
	char	*a_it;
	char	*b_it;

	getReady(a, b, &a_it, &b_it);
	while (--a_it >= a && --b_it >= b)
		*a_it = (*a_it ^ *b_it) ? '1' : '0';
	return (a);
}

int			toInt(char *bits)
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
