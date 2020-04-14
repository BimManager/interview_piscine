/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copyGameBoard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:30:34 by kkozlov           #+#    #+#             */
/*   Updated: 2020/02/25 18:49:02 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "header.h"

struct s_node	*nodenew(int value)
{
	struct s_node	*node;

	node = malloc(sizeof(struct s_node));
	node->value = value;
	node->next = NULL;
	node->random = NULL;
	return (node);
}

struct s_node	*cloneGameBoard(struct s_node *node)
{
	struct s_node	*curr;
	struct s_node	*dup;
	struct s_node	*ret;

	curr = node;
	while (curr)
	{
		dup = nodenew(curr->value);
		dup->next = curr->next;
		curr->next = dup;
		curr = dup->next;
	}
	curr = node;
	while (curr)
	{
		if (curr->random)
			curr->next->random = curr->random->next;
		curr = curr->next->next;
	}
	curr = node;
	ret = curr->next;
	while (curr)
	{
		dup = curr->next;
		curr->next = curr->next->next;
		if (dup->next)
			dup->next = dup->next->next;
		else
			dup->next = NULL;
		curr = curr->next;
	}
	return (ret);
}
