/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseV2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 15:52:19 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/18 15:56:55 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>

struct s_stack *stackInit(void)
{
	struct s_stack *stack = malloc(sizeof(struct s_stack));

	stack->item = NULL;
	return stack;
}

void push(struct s_stack *stack, char *word)
{
	struct s_item *new = malloc(sizeof(struct s_item));
	new->word = word;
	if (!stack)
		return;
	if (!stack->item)
	{
		new->next = NULL;
		stack->item = new;
		return;
	}
	new->next = stack->item;
	stack->item = new;
}

void *pop(struct s_stack *stack)
{
	if (!stack)
		return NULL;
	if (!stack->item)
		return NULL;

	struct s_item *current = stack->item;
	char *c;
	stack->item = stack->item->next;
	c = current->word;
	free(current);
	return c;
}

void printReverseV2(struct s_node *lst)
{
	struct s_stack *stack = stackInit();
	while (lst)
	{
		push(stack, lst->word);
		lst = lst->next;
	}
	while (stack->item)
		printf("%s ", pop(stack));
	printf("\n");
}
