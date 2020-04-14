/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:27:17 by kkozlov           #+#    #+#             */
/*   Updated: 2020/02/25 15:59:41 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

#include "header.h"

struct s_node	*nodenew(const char *message)
{
	struct s_node	*node;

	node = malloc(sizeof(struct s_node));
	node->next = NULL;
	if (message)
		node->message = strdup(message);
	else
		node->message = NULL;
	return (node);
}

struct s_queue	*queueInit(void)
{
	struct s_queue	*queue;

	queue = malloc(sizeof(struct s_queue));
	queue->first = NULL;
	queue->last = NULL;
	return (queue);
}

int				isEmpty(struct s_queue *queue)
{
	return (NULL == queue->first);
}

char			*dequeue(struct s_queue *queue)
{
	char			*message;
	struct s_node	*temp;

	if (isEmpty(queue))
		return (NULL);
	temp = queue->first;
	message = temp->message;
	if (queue->first == queue->last)
	{
		queue->first = NULL;
		queue->last = NULL;
	}
	else
		queue->first = queue->first->next;
	free(temp);
	return (message);
}

char			*peek(struct s_queue *queue)
{
	if (isEmpty(queue))
		return (NULL);
	return (queue->first->message);
}

void			enqueue(struct s_queue *queue, char *message)
{
	struct s_node	*node;

	node = nodenew(message);
	if (isEmpty(queue))
	{
		queue->first = node;
		queue->last = node;
		return ;
	}
	queue->last->next = node;
	queue->last = node;
}
