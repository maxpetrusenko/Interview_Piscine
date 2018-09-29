/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copyBoard.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 19:50:33 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/19 19:52:13 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>


int length(struct s_node *node)
{
	int len = 0;
	while (node)
	{
		node = node->next;
		len++;
	}
	return len;
}

struct s_node *cloneGameBoard(struct s_node *node)
{
	struct s_node *tmp = node;
	struct s_node *new = NULL;
	struct s_node *res;
	struct s_node *prev = NULL;
	int len = length(node);
	struct s_node *arr[len];

	while (tmp)
	{
		new = malloc(sizeof(struct s_node));
		new->value = tmp->value;
		new->random = NULL;
		if (prev)
			prev->next = new;
		else
			res = new;
		tmp = tmp->next;
		prev = new;
		arr[new->value] = new;
	}
	tmp = node;
	while (tmp)
	{
		if (tmp->random)
			arr[tmp->value]->random = arr[tmp->random->value];
		tmp = tmp->next;
	};
	return res;
}
