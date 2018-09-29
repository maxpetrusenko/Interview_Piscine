/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 20:14:24 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/18 20:22:37 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

void addStack(struct s_tank *tank)
{
	if (!tank)
		return;
	tank->n++;
	tank->stacks = realloc(tank->stacks, tank->n * sizeof(struct s_stack));
	struct s_stack *add = malloc(sizeof(struct s_stack));
	add->elem = NULL;
	add->sum = 0;
	tank->stacks[tank->n - 1] = add;
}

struct s_tank *initTank(void)
{
	struct s_tank *tank = malloc(sizeof(struct s_tank));
	if (!tank)
		return NULL;
	tank->n = 0;
	tank->stacks = NULL;
	return tank;
}

void stackPush(struct s_stack *stack, int energy)
{
	struct s_elem *pushed = malloc(sizeof(struct s_elem));
	if (!pushed)
		return;
	pushed->energy = energy;
	pushed->next = stack->elem;
	stack->elem = pushed;
	stack->sum += energy;
}

void tankPush(struct s_tank *tank, int energy)
{
	if (!tank)
		return;
	if (tank->n == 0 && energy != 0)
		addStack(tank);
	else if (tank->stacks[tank->n - 1]->sum + energy > 1000)
		addStack(tank);
	stackPush(tank->stacks[tank->n - 1], energy);
}

int stackPop(struct s_stack *stack)
{
	struct s_elem *elem = stack->elem;
	int diff = stack->elem->energy;
	stack->elem = stack->elem->next;
	stack->sum -= diff;
	free(elem);
	return diff;
}

void removeStack(struct s_tank *tank)
{
	free(tank->stacks[tank->n - 1]);
	tank->n--;
	if (tank->n == 0)
	{
		free(tank->stacks);
		tank->stacks = NULL;
	}
	else
		tank->stacks = realloc(tank->stacks, tank->n * sizeof(struct s_stack));
}

int tankPop(struct s_tank *tank)
{
	int energy;
	if (!tank)
		return 0;
	if (tank->n == 0)
		return 0;
	energy = stackPop(tank->stacks[tank->n - 1]);
	if (tank->stacks[tank->n - 1]->sum == 0)
		removeStack(tank);
	return energy;
}
