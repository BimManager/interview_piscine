/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortArts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 09:24:03 by kkozlov           #+#    #+#             */
/*   Updated: 2020/02/24 10:22:45 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

#include "header.h"

static void		ft_swap(void *pv1, void *pv2, size_t elem_size)
{
	void *buf;

	buf = malloc(elem_size * sizeof(char));
	memcpy(buf, pv1, elem_size);
	memcpy(pv1, pv2, elem_size);
	memcpy(pv2, buf, elem_size);
	free(buf);
}

static void		ft_qsort(void *base, size_t nel, size_t width,
					int (*compar)(const void *, const void *))
{
	void		*pivot;
	size_t		i;
	size_t		last;

	if (nel < 2)
		return ;
	pivot = (char *)base + (nel - 1) / 2 * width;
	ft_swap(base, pivot, width);
	i = 0;
	last = 0;
	while (++i < nel)
	{
		if (compar(base, (char *)base + i * width) > 0)
		{
			++last;
			ft_swap((char *)base + i * width,
				(char *)base + last * width, width);
		}
	}
	ft_swap(base, (char *)base + last * width, width);
	ft_qsort(base, last, width, compar);
	ft_qsort((char *)base + (last + 1) * width, nel - last - 1, width, compar);
}

static int		artcmp(const void *pv1, const void *pv2)
{
	struct s_art	**art_a;
	struct s_art	**art_b;

	art_a = (struct s_art **)pv1;
	art_b = (struct s_art **)pv2;
	return (strcmp((*art_a)->name, (*art_b)->name));
}

static size_t	artcount(struct s_art **arts)
{
	size_t	n;

	n = 0;
	while (arts[n])
		++n;
	return (n);
}

void			sortArts(struct s_art **arts)
{
	ft_qsort(arts, artcount(arts), sizeof(void *), &artcmp);
}
