/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:26:50 by kkozlov           #+#    #+#             */
/*   Updated: 2020/02/24 12:10:56 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "header.h"

int	searchPrice(struct s_art **arts, int n, char *name)
{
	int	cmp;
	int	lhs;
	int	rhs;

	lhs = 0;
	rhs = n;
	while (lhs <= rhs)
	{
		cmp = strcmp(arts[(lhs + rhs) / 2]->name, name);
		if (0 == cmp)
			return (arts[(lhs + rhs) / 2]->price);
		else if (0 < cmp)
			rhs = (lhs + rhs) / 2 - 1;
		else
			lhs = (lhs + rhs) / 2 + 1;
	}
	return (-1);
}
