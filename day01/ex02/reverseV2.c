/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseV2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:13:37 by kkozlov           #+#    #+#             */
/*   Updated: 2020/02/25 11:32:50 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "header.h"

struct s_item	*itemnew(const char *word)
{
	struct s_item	*item;

	item = malloc(sizeof(struct s_item));
	item->next = NULL;
	if (word)
		item->word = strdup(word);
	else
		item->word = NULL;
	return (item);
}

struct s_stack	*stackInit(void)
{
	struct s_stack	*stack;

	stack = malloc(sizeof(struct s_stack));
	stack->item = NULL;
	return (stack);
}

int				is_empty(struct s_stack *stack)
{
	return (NULL == stack->item);
}

void			*pop(struct s_stack *stack)
{
	char			*content;
	struct s_item	*temp;

	if (is_empty(stack))
		return (NULL);
	content = stack->item->word;
	temp = stack->item;
	stack->item = stack->item->next;
	free(temp);
	return (content);
}

void			push(struct s_stack *stack, char *word)
{
	struct s_item	*item;

	item = itemnew(word);
	if (is_empty(stack))
		stack->item = item;
	else
	{
		item->next = stack->item;
		stack->item = item;
	}
}

void			*peek(struct s_stack *stack)
{
	if (is_empty(stack))
		return (NULL);
	return (stack->item->word);
}

void			printReverseV2(struct s_node *lst)
{
	struct s_node	*it;
	struct s_stack	*stack;
	char			*word;

	stack = stackInit();
	it = lst;
	while (it)
	{
		push(stack, it->word);
		it = it->next;
	}
	while (!is_empty(stack))
	{
		word = pop(stack);
		printf("%s", word);
		free(word);
		if ((word = peek(stack)))
			printf(" ");
	}
}
