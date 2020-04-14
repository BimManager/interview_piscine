/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createBST.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:49:02 by kkozlov           #+#    #+#             */
/*   Updated: 2020/02/28 09:22:28 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "header.h"

static struct s_node	*nodenew(int val)
{
	struct s_node	*node;

	node = malloc(sizeof(struct s_node));
	node->left = NULL;
	node->right = NULL;
	node->value = val;
	return (node);
}

struct s_node			*createBST(int *arr, int n)
{
	struct s_node	*node;
	int				pivot;

	if (!n)
		return (NULL);
	if (1 == n)
		return (nodenew(arr[0]));
	pivot = n / 2;
	node = nodenew(arr[pivot]);
	node->left = createBST(arr, pivot);
	node->right = createBST(arr + pivot + 1, n - pivot - 1);
	return (node);
}
