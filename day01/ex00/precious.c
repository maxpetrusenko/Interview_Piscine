/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precious.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 13:07:11 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/18 15:39:46 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdlib.h>

struct s_node *createElem(char c)
{
	struct s_node *list;

	list = (struct s_node *)malloc(sizeof(struct s_node));
	list->c = c;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

void insert(struct s_node **head, char c)
{
	if (*head == NULL)
	{
		*head = createElem(c);
		(*head)->next = (*head);
		(*head)->prev = (*head);
		return;
	}
	struct s_node *node = createElem(c);
	node->next = *head;
	node->prev = (*head)->prev;
	(*head)->prev->next = node;
	(*head)->prev = node;
}

char *precious(int *text, int size)
{
	char *str = malloc(size + 1);
	struct s_node *list = NULL;
	int rot = 0;
	if (size < 0)
		return (NULL);
	for (int i = 0; CS[i] != '\0'; i++)
		insert(&list, CS[i]);
	for (int j = 0; j < size; j++)
	{
		rot = text[j];
		if (rot >= 0)
			while (rot--)
				list = list->next;
		else
			while (rot++)
				list = list->prev;
		str[j] = list->c;
	}
	return (str);
}
