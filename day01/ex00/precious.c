/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precious.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 09:39:11 by kkozlov           #+#    #+#             */
/*   Updated: 2020/02/25 10:27:42 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "header.h"

struct s_node	*nodenew(char c)
{
	struct s_node	*node;

	node = malloc(sizeof(struct s_node));
	node->prev = NULL;
	node->next = NULL;
	node->c = c;
	return (node);
}

struct s_dblst	*dblstnew(void)
{
	struct s_dblst	*dblst;

	dblst = malloc(sizeof(struct s_dblst));
	dblst->head = NULL;
	return (dblst);
}

void			dblstsnoc(struct s_dblst *dblst, char c)
{
	struct s_node	*node;

	node = nodenew(c);
	if (!dblst->head)
	{
		node->next = node;
		node->prev = node;
		dblst->head = node;
		return ;
	}
	dblst->head->prev->next = node;
	node->prev = dblst->head->prev;
	node->next = dblst->head;
	dblst->head->prev = node;
}

char			dblstgetn(struct s_dblst *dblst, int n)
{
	struct s_node	*it;

	it = dblst->head;
	if (n > 0)
		while (n--)
			it = it->next;
	else
		while (n++)
			it = it->prev;
	dblst->head = it;
	return (it->c);
}

struct s_dblst	*dblstprep(void)
{
	struct s_dblst	*dblst;
	char			*it;

	dblst = dblstnew();
	it = CS;
	while (*it)
		dblstsnoc(dblst, *it++);
	return (dblst);
}

char			*precious(int *text, int size)
{
	char			*dch;
	char			*it;
	struct s_dblst	*dblst;
	int				i;

	if (!text)
		return (NULL);
	dch = malloc((size + 1) * sizeof(char));
	dch[size] = '\0';
	it = dch;
	dblst = dblstprep();
	i = -1;
	while (++i < size)
		*it++ = dblstgetn(dblst, text[i]);
	return (dch);
}
