/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   junkFood.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 10:12:02 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/06 12:13:58 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

#include "header.h"

#include <stdio.h>

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


//static void			xsellers_util(struct

static void			enqueueNeighbours(struct s_queue *queue,
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

struct s_sellers	*xfind_sellers(struct s_node *start_node)
{
	struct s_queue		*queue;
	struct s_node		*curr;
	struct s_sellers	*sellers;
//	int					dist;
	int					count;

	queue = queueInit();
	enqueueNeighbours(queue, start_node->connectedPlaces, 1);
//	enqueue(queue, sentinelnew());
	sellers = sellersnew(100);
//	dist = 1;
	count = 0;
	while (!queueIsEmpty(queue))
	{
		if (!(curr = dequeue(queue))->name)
		{
			enqueue(queue, curr);
			++sellers->distance;
//			++dist;
			if (*sellers->placeNames)
				return (sellers);
			continue ;
		}
//		printf("curr: %p name: %s hasBars: %d dist: %d\n",
//			   curr, curr->name, curr->hasCerealBar, dist);
		if (curr->hasCerealBar && !curr->visited)
			sellers->placeNames[count++] = curr->name;
//		{
//			if (!*(sellers->placeNames))
//			{
//			if (!curr->visited)
		//			sellers->placeNames[count++] = curr->name;
//				sellers->distance = dist;
				//		}
//			else if (dist == sellers->distance && !curr->visited)
//				sellers->placeNames[count++] = curr->name;
//			else if (dist > sellers->distance)
//				break ;
//		}
		curr->visited = 1;
		enqueueNeighbours(queue, curr->connectedPlaces, 0);
	}
	return (sellers);
}

struct s_sellers	*closestSellers(struct s_graph *parisPlaces, char *youAreHere)
{

	struct s_node	*start_node;

	if (!(start_node = findStartNode(parisPlaces, youAreHere)))
		return (NULL);
	return (xfind_sellers(start_node));
}

