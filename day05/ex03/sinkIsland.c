/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sinkIsland.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 12:28:31 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/03 12:49:57 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	xsink(int **map, int row, int col)
{
	if (row < 0 || col < 0 || !map[row]
		|| -1 == map[row][col])
		return ;
	if (1 != map[row][col])
		return ;
	map[row][col] = 0;
	xsink(map, row - 1, col);
	xsink(map, row + 1, col);
	xsink(map, row, col - 1);
	xsink(map, row, col + 1);
}

void		sinkIsland(int **map, int row, int col)
{
	int	n_rows;
	int	n_cols;

	n_rows = 0;
	while (map[n_rows])
		++n_rows;
	n_cols = 0;
	while (-1 != *(*map + n_cols))
		++n_cols;
	if (row >= n_rows || col >= n_cols)
		return ;
	xsink(map, row, col);
}
