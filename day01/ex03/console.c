/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:34:29 by kkozlov           #+#    #+#             */
/*   Updated: 2020/02/25 15:26:09 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "header.h"

struct s_item	*itemnew(int idx)
{
	struct s_item	*item;

	item = malloc(sizeof(struct s_item));
	item->next = NULL;
	item->idx = idx;
	return (item);
}

struct s_stack	*initStack(void)
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

int				pop(struct s_stack *stack)
{
	int				idx;
	struct s_item	*temp;

	if (is_empty(stack))
		return (-1);
	idx = stack->item->idx;
	temp = stack->item;
	stack->item = stack->item->next;
	free(temp);
	return (idx);
}

void			push(struct s_stack *stack, int idx)
{
	struct s_item	*item;

	item = itemnew(idx);
	if (is_empty(stack))
		stack->item = item;
	else
	{
		item->next = stack->item;
		stack->item = item;
	}
}

int				peek(struct s_stack *stack)
{
	if (is_empty(stack))
		return (-1);
	return (stack->item->idx);
}

char			*console(void)
{
	struct s_stack	*stack;
	char			*line;
	size_t			cap;
	static char		buffer[256];
	int				idx;

	stack = initStack();
	idx = 0;
	while (printf("?: ") && (getline(&line, &cap, stdin)) > 0)
	{
		if (0 == strcmp(line, "UNDO\n"))
			idx = pop(stack);
		else if (0 == strcmp(line, "SEND\n"))
			break ;
		else
		{
			push(stack, idx);
			strncpy(buffer + idx, line, strlen(line) - 1);
			idx += strlen(line) - 1;
		}
		printf("%.*s\n\n", idx, buffer);
	}
	buffer[idx] = '\0';
	return (buffer);
}
