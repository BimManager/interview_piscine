/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findParent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 09:29:20 by kkozlov           #+#    #+#             */
/*   Updated: 2020/02/28 11:11:35 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "header.h"

#include <stdio.h>

static void				bothPresent(struct s_node *root, char *firstSpecies,
							char *secondSpecies, int *n_matches)
{
	struct s_node	**it;

	if (!root)
		return ;
	if (0 == strcmp(root->name, firstSpecies) 
		|| 0 == strcmp(root->name, secondSpecies))
		*n_matches += 1;
	it = root->children;
	while (*it)
	{
		bothPresent(*it, firstSpecies, secondSpecies, n_matches);
		++it;
	}
}

static struct s_node	*xfindParent(struct s_node *root, char *firstSpecies,
							char *secondSpecies)
{
	struct s_node	**it;
	struct s_node	*temp;
	struct s_node	*saved;
	int				n_matches;

	if (!root)
		return (NULL);
	if (0 == strcmp(root->name, firstSpecies)
		|| 0 == strcmp(root->name, secondSpecies))
		return (root);
	it = root->children;
	temp = NULL;
	saved = NULL;
	n_matches = 0;
	while (*it)
	{
		if ((temp = xfindParent(*it, firstSpecies, secondSpecies)))
		{
			saved = temp;
			++n_matches;
		}
		if (2 == n_matches)
			return (root);
		++it;
	}
	return (saved);
}

struct s_node			*findParent(struct s_node *root, char *firstSpecies,
							char *secondSpecies)
{
	int	n_matches;

	n_matches = 0;
	bothPresent(root, firstSpecies, secondSpecies, &n_matches);
	if (2 == n_matches)
		return (xfindParent(root, firstSpecies, secondSpecies));
	return (NULL);
}
