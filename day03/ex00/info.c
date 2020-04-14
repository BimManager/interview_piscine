/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 08:47:48 by kkozlov           #+#    #+#             */
/*   Updated: 2020/02/27 16:46:19 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

#include "header.h"

static int		getMaxBST(struct s_node *root)
{
	if (!root)
		return (0);
	if (root->right)
		return (getMaxBST(root->right));
	return (root->value);
}

static int		getMinBST(struct s_node *root)
{
	if (!root)
		return (0);
	if (root->left)
		return (getMinBST(root->left));
	return (root->value);
}

static void		xgetMax(struct s_node *root, int *max)
{
	if (!root)
		return ;
	xgetMax(root->left, max);
	if (root->value > *max)
		*max = root->value;
	xgetMax(root->right, max);
}

static int		getMax(struct s_node *root)
{
	int	max;

	max = root->value;
	xgetMax(root, &max);
	return (max);
}

static void		xgetMin(struct s_node *root, int *min)
{
	if (!root)
		return ;
	xgetMin(root->left, min);
	if (root->value < *min)
		*min = root->value;
	xgetMin(root->right, min);
}

static int		getMin(struct s_node *root)
{
	int	min;

	min = root->value;
	xgetMin(root, &min);
	return (min);
}

static int		getElementCount(struct s_node *root)
{
	if (!root)
		return (0);
	return (1 + getElementCount(root->left) + getElementCount(root->right));
}

static int		getHeight(struct s_node *root)
{
	if (!root)
		return (-1);
	return (1 + XMAX(getHeight(root->left),
					getHeight(root->right)));
}

static int		xisBST(struct s_node *root, int min , int max)
{
	if (!root)
		return (1);
	return (xisBST(root->left, min, root->value)
		&& min <= root->value && max >= root->value
		&& xisBST(root->right, root->value, max));
}

static int		isBST(struct s_node *root)
{
	if (!root)
		return (0);
	return (xisBST(root, INT_MIN, INT_MAX));
			
}

/*
** An empty tree is balanced
** A tree is balanced if
** - its left sub-tree is balanced
** - its right sub-tree is balanced
** - the difference between the heights of
** the left sub-tree and the right sub-tree
** is less than 2
*/

static int		isBalanced(struct s_node *root)
{
	if (!root)
		return (1);
	return(isBalanced(root->left)
		   && isBalanced(root->right)
		   && (abs(getHeight(root->left)
				   - getHeight(root->right)) < 2));
}

struct s_info	getInfo(struct s_node *root)
{
	struct s_info	info;

	info.min = isBST(root) ? getMinBST(root) : getMin(root);
	info.max = isBST(root) ? getMaxBST(root) : getMax(root);
	info.elements = getElementCount(root);
	info.height = getHeight(root);
	info.isBST = isBST(root);
	info.isBalanced = isBalanced(root);
	return (info);
}
