/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:03:29 by kkozlov           #+#    #+#             */
/*   Updated: 2020/02/25 17:11:47 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

#include "header.h"

struct s_elem	*elemnew(int energy)
{
	struct s_elem	*elem;

	elem = malloc(sizeof(struct s_elem));
	elem->next = NULL;
	elem->energy = energy;
	return (elem);
}

struct s_stack	*initStack(void)
{
	struct s_stack	*stack;

	stack = malloc(sizeof(struct s_stack));
	stack->elem = NULL;
	stack->sum = 0;
	return (stack);
}

int				isEmpty(struct s_stack *stack)
{
	return (NULL == stack->elem);
}

int				pop(struct s_stack *stack)
{
	int				energy;
	struct s_elem	*temp;

	if (isEmpty(stack))
		return (-1);
	energy = stack->elem->energy;
	temp = stack->elem;
	stack->elem = stack->elem->next;
	free(temp);
	stack->sum -= energy;
	return (energy);
}

void			push(struct s_stack *stack, int energy)
{
	struct s_elem	*elem;

	elem = elemnew(energy);
	if (isEmpty(stack))
		stack->elem = elem;
	else
	{
		elem->next = stack->elem;
		stack->elem = elem;
	}
	stack->sum += energy;
}

int				peek(struct s_stack *stack)
{
	if (isEmpty(stack))
		return (-1);
	return (stack->elem->energy);
}

struct s_tank	*initTank(void)
{
	struct s_tank	*tank;

	tank = malloc(sizeof(struct s_tank));
	tank->n = 0;
	tank->stacks = malloc(256 * sizeof(void *));
	bzero(tank->stacks, 256 * sizeof(void *));
	return (tank);
}

void			tankPush(struct s_tank *tank, int energy)
{
	struct s_stack	*stack;

	if (!(stack = tank->stacks[tank->n]))
		tank->stacks[tank->n] = initStack();
	stack = tank->stacks[tank->n];
	if (stack->sum + energy <= MAX_CAPACITY)
	{
		push(stack, energy);
		return ;
	}
	tank->n += 1;
	tank->stacks[tank->n] = initStack();
	stack = tank->stacks[tank->n];
	push(stack, energy);
}

int				tankPop(struct s_tank *tank)
{
	struct s_stack	*stack;
	int				energy;

	if (!(stack = tank->stacks[tank->n]))
		return (-1);
	energy = pop(stack);
	if (isEmpty(stack))
	{
		free(stack);
		tank->stacks[tank->n] = NULL;
		tank->n -= 1;
	}
	return (energy);
}

int				tankIsEmpty(struct s_tank *tank)
{
	return (NULL == tank->stacks[0]);
}
