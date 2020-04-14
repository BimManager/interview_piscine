/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   knightOut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 09:53:19 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/05 16:31:35 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "header.h"

static int		popcount64(uint64_t x)
{
	x = (x & M1) + ((x >> 1) & M1);
	x = (x & M2) + ((x >> 2) & M2);
	x = (x & M4) + ((x >> 4) & M4);
	x = (x & M8) + ((x >> 8) & M8);
	x = (x & M16) + ((x >> 16) & M16);
	x = (x & M32) + ((x >> 32) & M32);
	return (x);
}

static int		clz3(uint64_t x)
{
	int	n;

	if (!x)
		return (-1);
	n = 0;
	if (!(x & 0xffffffff00000000) && (n += 32))
		x <<= 32;
	if (!(x & 0xffff000000000000) && (n += 16))
		x <<= 16;
	if (!(x & 0xff00000000000000) && (n += 8))
		x <<= 8;
	if (!(x & 0xf000000000000000) && (n += 4))
		x <<= 4;
	if (!(x & 0xc000000000000000) && (n += 2))
		x <<= 2;
	if (!(x & 0x8000000000000000))
		n += 1;
	return (0x3f - n);
}

int				getInitialPos(uint64_t board)
{
	if (1 != popcount64(board))
		return (-1);
	return (clz3(board));
}

static double	knight_prob(int n_moves, int srow, int scol)
{
	double	dp[WIDTH][WIDTH];
	double	dp2[WIDTH][WIDTH];
	int		dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
	int		dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};
	double	res;
	int		data[8];

	bzero(dp, sizeof(dp));
	dp[srow][scol] = 1;
	while (n_moves--)
	{
		bzero(dp2, sizeof(dp2));
		data[ROW] = -1;
		while (++data[ROW] < WIDTH)
		{
			data[COL] = -1;
			while (++data[COL] < WIDTH)
			{
				data[K] = -1;
				while (++data[K] < WIDTH)
				{
					data[DROW] = data[ROW] + dr[data[K]];
					data[DCOL] = data[COL] + dc[data[K]];
					if ((0 <= data[DROW] && WIDTH > data[DROW])
						&& (0 <= data[DCOL] && WIDTH > data[DCOL]))
						dp2[data[DROW]][data[DCOL]] += dp[data[ROW]][data[COL]] / 8.0;
				}
			}
		}
		memcpy(dp, dp2, sizeof(dp));
	}
	res = 0.0;
	data[ROW] = -1;
	while (++data[ROW] < WIDTH)
	{
		data[COL] = -1;
		while (++data[COL] < WIDTH)
			res += dp[data[ROW]][data[COL]];
	}
	return (1.0 - res);
}

double			knightOut(uint64_t board, int n)
{
	int	pos;

	if (-1 == (pos = getInitialPos(board)) || 0 > n)
		return (-1);
	return (knight_prob(n, ROW(pos), COL(pos)));
}
