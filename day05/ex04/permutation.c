/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 13:11:31 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/03 13:16:39 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

static void	xswap(char *c1, char *c2)
{
	*c1 ^= *c2;
	*c2 ^= *c1;
	*c1 ^= *c2;
}

static void	xgenerate(char *str, int k)
{
	int	i;

	if (1 == k)
	{
		printf("%s\n", str);
		return ;
	}
	xgenerate(str, k - 1);
	i = -1;
	while (++i < k - 1)
	{
		if (0 == k % 2)
			xswap(&str[i], &str[k - 1]);
		else
			xswap(&str[0], &str[k - 1]);
		xgenerate(str, k - 1);
	}
}

void		printPermutations(char *str)
{
	if (!str)
		return ;
	xgenerate(str, strlen(str));
}
