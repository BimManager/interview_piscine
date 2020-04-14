/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piano.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:01:47 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/02 08:49:22 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "header.h"

int	**pianoDecompress(struct s_bit *bit, int l)
{
	int	**matrix;
	int	i;
	int	j;
	int	n;

	n = bit->n;
	matrix = malloc(n * sizeof(void *));
	i = -1;
	while (++i < n)
	{
		matrix[i] = malloc(l * sizeof(int));
		j = -1;
		while (++j < l)
			matrix[i][j] = (bit->arr)[i] & (1 << j) ? 1 : 0;
	}
	return (matrix);
}
