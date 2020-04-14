/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutationV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 13:23:08 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/03 13:28:59 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

#include "header.h"

static void	xswap(char *c1, char *c2)
{
	*c1 ^= *c2;
	*c2 ^= *c1;
	*c1 ^= *c2;
}

static void	xgenerate(char *str, int k, struct s_dict *dict)
{
	int	i;

	if (1 == k)
	{
		if (-1 == dictSearch(dict, str))
		{
			dictInsert(dict, str, 42);
			printf("%s\n", str);
		}
		return ;
	}
	xgenerate(str, k - 1, dict);
	i = -1;
	while (++i < k - 1)
	{
		if (0 == k % 2)
			xswap(&str[i], &str[k - 1]);
		else
			xswap(&str[0], &str[k - 1]);
		xgenerate(str, k - 1, dict);
	}
}

void		printUniquePermutations(char *str)
{
	struct s_dict	*dict;

	if (!str)
		return ;
	dict = dictInit(strlen(str));
	xgenerate(str, strlen(str), dict);
}
