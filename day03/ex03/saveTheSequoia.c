/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saveTheSequoia.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 11:39:55 by kkozlov           #+#    #+#             */
/*   Updated: 2020/02/28 18:57:40 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	nodecmp(struct s_node *na, struct s_node *nb)
{
	if (na->value > nb->value)
		return (1);
	else if (na->value < nb->value)
		return (-1);
	return (0);
}

#include <stdio.h>

static void	nodeSwapLeft(struct s_node **parent,
						  struct s_node *n1, struct s_node *n2)
{
	struct s_node	*temp;

	if (*parent == n1)
	{
		*parent = n2;
		n1->left = n2->left;
		n2->left = n1;
		temp = n1->right;
		n1->right = n2->right;
		n2->right = temp;
		return ;
	}
	if (!n2)
	{
		(*parent)->left = n1->left;
		n1->left = *parent;
		temp = (*parent)->right;
		(*parent)->right = n1->right;
		n1->right = temp;
		*parent = n1;
		return ;
	}
	n1->left = n2->left;
	n2->left = n1;
	temp = n1->right;
	n1->right = n2->right;
	n2->right = temp;
	(*parent)->left = n2;
}

static void	nodeSwapRight(struct s_node **parent,
						  struct s_node *n1, struct s_node *n2)
{
	struct s_node	*temp;

	if (*parent == n1)
	{
		*parent = n2;
		n1->right = n2->right;
		n2->right = n1;
		temp = n1->left;
		n1->left = n2->left;
		n2->left = temp;
		return ;
	}
	else if (!n2)
	{
		(*parent)->right = n1->right; 
		n1->right = *parent;
		temp = (*parent)->left;
		(*parent)->left = n1->left;
		n1->left = temp;
		*parent = n1;
		return ;
	}
	n1->right = n2->right;
	temp = n1->left;
	n1->left = n2->left;
	n2->left = temp;
	n2->right = n1;
	(*parent)->right = n2;
}

static void	maxHeapify(struct s_node **parent, struct s_node *node)
{
	struct s_node	*largest;
	if (!node)
		return ;
	printf("parent: %d node: %d\n", (*parent)->value, node->value);
	largest = node;
	if (node->left)
		if (nodecmp(largest, node->left) < 0)
			largest = node->left;
	if (node->right)
		if (nodecmp(largest, node->right) < 0)
			largest = node->right;
	if ((*parent)->value >= node->value)
	{
//		if (largest == node->right)
		if ((*parent)->right == node)
		{
			nodeSwapRight(parent, node, node->right);
			maxHeapify(&(*parent)->right, (*parent)->right->right);
		}
		else
		{
			nodeSwapLeft(parent, node, node->left);
//			printBinaryTree(*parent);
			maxHeapify(&(*parent)->left, (*parent)->left->left);
		}
		printf("swap done\n");
	}
}


void	saveTheSequoia(struct s_node **root)
{
//	nodeSwapLeft(root, *root, (*root)->left);
//	nodeSwapRight(root, *root, (*root)->right);
//	nodeSwapLeft(root, *root, (*root)->left);
//	nodeSwapLeft(root, (*root)->left, NULL);
//	nodeSwapLeft(root, (*root)->left, (*root)->left->left);
	maxHeapify(root, *root);
//	maxHeapify(root, (*root)->right);
}
