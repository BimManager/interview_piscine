/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howManyJesus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:54:46 by kkozlov           #+#    #+#             */
/*   Updated: 2020/02/24 15:48:29 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

#include "header.h"

static size_t	xhash(const char *key)
{
	size_t	hs;
	int		i;

	hs = 0;
	i = -1;
	while (key[++i])
		hs = (hs * PRIME_BASE + key[i]) % PRIME_MOD;
	return (hs);
}

/*
** data[0]: pattern hash
** data[1]: substring hash
** data[2]: power
** help[0]: count
** help[1]: counter
** help[2]: pattern lenth
*/

int				howManyJesus(char *bible, char *jesus)
{
	long long	data[3];
	int			help[3];

	data[0] = xhash(jesus);
	data[1] = 0;
	data[2] = 1;
	help[0] = 0;
	help[1] = -1;
	help[2] = strlen(jesus);
	while (jesus[++help[1]])
		data[2] = (data[2] * PRIME_BASE) % PRIME_MOD;
	help[1] = -1;
	while (bible[++help[1]])
	{
		data[1] = (data[1] * PRIME_BASE + bible[help[1]]) % PRIME_MOD;
		if (help[1] >= help[2])
		{
			data[1] -= data[2] * bible[help[1] - help[2]] % PRIME_MOD;
			if (data[1] < 0)
				data[1] += PRIME_MOD;
		}
		if ((help[1] >= help[2] - 1) && (data[0] == data[1]))
			++help[0];
	}
	return (help[0]);
}
