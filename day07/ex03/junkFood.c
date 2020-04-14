/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   junkFood.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 10:12:02 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/06 12:57:13 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

#include "header.h"

int						queueIsEmpty(struct s_queue *queue)
{
	return (NULL == queue->first);
}

static struct s_sellers	*sellersnew(int capacity)
{
	struct s_sellers	*sellers;

	sellers = malloc(sizeof(struct s_sellers));
	sellers->distance = 0;
	sellers->placeNames = malloc(capacity * sizeof(void *));
	bzero(sellers->placeNames, capacity * sizeof(void *));
	return (sellers);
}

static struct s_node	*sentinelnew(void)
{
	struct s_node	*sentinel;

	sentinel = malloc(sizeof(struct s_node));
	sentinel->name = NULL;
	sentinel->connectedPlaces = NULL;
	sentinel->visited = 0;
	sentinel->hasCerealBar = 0;
	return (sentinel);
}

static struct s_node	*findStartNode(struct s_graph *parisPlaces,
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

static void				enqueueNeighbours(struct s_queue *queue,
							struct s_node **it, int add_sentinel)
{
	while (*it)
	{
		if (!(*it)->visited)
			enqueue(queue, (*it));
		++it;
	}
	if (add_sentinel)
		enqueue(queue, sentinelnew());
}

struct s_sellers		*xfind_sellers(struct s_node *start_node)
{
	struct s_queue		*queue;
	struct s_node		*curr;
	struct s_sellers	*sellers;
	char				**names_it;

	queue = queueInit();
	sellers = sellersnew(420);
	names_it = sellers->placeNames;
	if (start_node->hasCerealBar && (*names_it++ = start_node->name))
		return (sellers);
	start_node->visited = 1;
	enqueueNeighbours(queue, start_node->connectedPlaces, 1);
	while (!queueIsEmpty(queue))
	{
		if (!(curr = dequeue(queue))->name)
		{
			++sellers->distance;
			if (*sellers->placeNames)
				return (sellers);
			if (queueIsEmpty(queue))
			{
				--sellers->distance;
				return (sellers);
			}
			enqueue(queue, curr);
			continue ;
		}
		if (curr->hasCerealBar && !curr->visited)
			*names_it++ = curr->name;
		curr->visited = 1;
		enqueueNeighbours(queue, curr->connectedPlaces, 0);
	}
	return (sellers);
}

struct s_sellers		*closestSellers(struct s_graph *parisPlaces,
									char *youAreHere)
{
	struct s_node	*start_node;

	if (!(start_node = findStartNode(parisPlaces, youAreHere)))
		return (NULL);
	return (xfind_sellers(start_node));
}
