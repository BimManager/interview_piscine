/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxTraffic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 12:59:38 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/06 14:34:58 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "header.h"


#include <stdio.h>

int						queueIsEmpty(struct s_queue *queue)
{
	return (NULL == queue->first);
}

static struct s_node	*sentinelnew(void)
{
	struct s_node	*sentinel;

	sentinel = malloc(sizeof(struct s_node));
	sentinel->name = NULL;
	sentinel->connectedPlaces = NULL;
	sentinel->visited = 0;
	sentinel->population = 0;
	return (sentinel);
}

static struct s_node	*findEventNode(struct s_graph *parisPlaces,
										char *youAreHere)
{
	struct s_node	**it;

	it = parisPlaces->places;
	while (*it)
	{
		if (0 == strcmp((*it)->name, youAreHere))
			return (*it);
		++it;
	}
	return (NULL);
}

static float		bfs(struct s_node *startNode, struct s_node *destNode,
						int *n_paths)
{
	struct s_queue	*queue;
	struct s_node	*curr;
	struct s_node	**it;
	int				min_depth;
	double			pop;
	int				depth;

	queue = queueInit();
	enqueue(queue, startNode);
	enqueue(queue, sentinelnew());
	pop = 0.0;
	depth = 0;
	while (!queueIsEmpty(queue))
	{
		printf("exploring...\n");
		if (!(curr = dequeue(queue))->name)
		{
			++depth;
			if (queueIsEmpty(queue))
				return (0.0);
			enqueue(queue, curr);
			continue ;
		}
		if (0 == strcmp(curr->name, destNode->name))
		{
			printf("startNode: %s\n", startNode->name);
			if (0 == *n_paths)
			{
				++*n_paths;
				min_depth = depth;
			}
			else if (depth == min_depth)
				++*n_paths;
			else if (depth < min_depth)
			{
				*n_paths = 1;
				min_depth = depth;
			}
//			*depth = 0;
		}
		curr->visited = 1;
		pop += curr->population;
		it = curr->connectedPlaces;
		while (*it)
		{
			if (!(*it)->visited)
				enqueue(queue, *it);
			++it;
		}
//		printf("depth: %d pop: %f\n", depth, pop);
	}
	return (pop);
}

float				maxTraffic(struct s_graph *parisPlaces, char *eventHere)
{
	struct s_node	*eventNode;
	struct s_node	**it;
	int				n_paths;
	float			total;
	float			temp;
	
	if (!(eventNode = findEventNode(parisPlaces, eventHere)))
		return (-1);
	total = 0.0;
	it = parisPlaces->places;
	while (*it)
	{
		printf("node to check: %s\n", (*it)->name);
		if (0 != strcmp((*it)->name, eventHere))
		{
			temp = bfs(*it, eventNode, &n_paths);
			printf("node: %s n_paths: %d\n", (*it)->name, n_paths);
			n_paths = 0;
		}
		++it;

	}
	return (total);
}
