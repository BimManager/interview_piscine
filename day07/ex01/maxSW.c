/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxSW.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 11:22:17 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/06 09:51:51 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "header.h"

struct s_dequeNode	*nodenew(int value)
{
	struct s_dequeNode	*node;

	node = malloc(sizeof(struct s_dequeNode));
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

struct s_deque		*dequeInit(void)
{
	struct s_deque	*deque;

	deque = malloc(sizeof(struct s_deque));
	deque->first = NULL;
	deque->last = NULL;
	return (deque);
}

int					isEmpty(struct s_deque *deque)
{
	return (NULL == deque->first);
}

void				pushFront(struct s_deque *deque, int value)
{
	struct s_dequeNode	*node;

	node = nodenew(value);
	if (isEmpty(deque))
	{
		deque->first = node;
		deque->last = node;
		return ;
	}
	node->next = deque->first;
	deque->first->prev = node;
	deque->first = node;
}

void				pushBack(struct s_deque *deque, int value)
{
	struct s_dequeNode	*node;

	node = nodenew(value);
	if (isEmpty(deque))
	{
		deque->first = node;
		deque->last = node;
		return ;
	}
	deque->last->next = node;
	node->prev = deque->last;
	deque->last = node;
}

int					popFront(struct s_deque *deque)
{
	struct s_dequeNode	*temp;
	int					value;

	if (isEmpty(deque))
		return (INT_MIN);
	temp = deque->first;
	if (deque->first == deque->last)
		deque->last = NULL;
	else
		deque->first->next->prev = NULL;
	deque->first = temp->next;
	value = temp->value;
	free(temp);
	return (value);
}

int					popBack(struct s_deque *deque)
{
	struct s_dequeNode	*temp;
	int					value;

	if (isEmpty(deque))
		return (INT_MIN);
	temp = deque->last;
	if (deque->last == deque->first)
		deque->first = NULL;
	else
		deque->last->prev->next = NULL;
	deque->last = temp->prev;
	value = temp->value;
	free(temp);
	return (value);
}

int					peekFront(struct s_deque *deque)
{
	if (isEmpty(deque))
		return (INT_MIN);
	return (deque->first->value);
}

int					peekBack(struct s_deque *deque)
{
	if (isEmpty(deque))
		return (INT_MIN);
	return (deque->last->value);
}

struct s_max		*maxnew(int length)
{
	struct s_max	*max;

	max = malloc(sizeof(max));
	max->length = length;
	max->max = malloc(length * sizeof(int));
	bzero(max->max, length * sizeof(int));
	return (max);
}

struct s_max		*maxSlidingWindow(int *arr, int n, int k)
{
	struct s_deque	*deque;
	struct s_max	*max;
	int				i;

	max = maxnew(n - k + 1);
	deque = dequeInit();
	max->max[0] = INT_MIN;
	i = -1;
	while (++i < k)
	{
		if (arr[i] > max->max[0])
			max->max[0] = arr[i];
		while (!isEmpty(deque) && arr[i] >= arr[peekBack(deque)])
			popBack(deque);
		pushBack(deque, i);
	}
	--i;
	while (++i < n)
	{
		max->max[i - k] = arr[peekFront(deque)];
		while (!isEmpty(deque) && peekFront(deque) <= i - k)
			popFront(deque);
		while (!isEmpty(deque) && arr[peekBack(deque)] <= arr[i])
			popBack(deque);
		pushBack(deque, i);
	}
	max->max[i - k] = arr[popFront(deque)];
	return (max);
}
