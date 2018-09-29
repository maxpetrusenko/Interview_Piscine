/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxTraffic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 21:11:46 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/28 21:12:20 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdlib.h>

float maxTraffic(struct s_graph *parisPlaces, char *eventHere)
{
	printf("here\n");
	struct s_node *start = NULL;
	for (int i = 0; parisPlaces->places[i]; i++)
	{
		if (strcmp(eventHere, parisPlaces->places[i]->name) == 0)
		{
			start = parisPlaces->places[i];
			break;
		}
	}
	if (!start)
	{
		printf("NO\n");
		return -1.0;
	}
	struct s_queue *q = queueInit();
	struct s_node *temp;
	float pop = 0;
	int count;
	for (int i = 0; start->connectedPlaces[i]; i++)
	{
		start->connectedPlaces[i]->visited = 1;
		enqueue(q, start->connectedPlaces[i]);
		if (start->connectedPlaces[i]->population > pop)
			pop = start->connectedPlaces[i]->population;
	}
	while ((temp = dequeue(q)))
	{
		temp->visited = 1;
		count = 0;
		for (int i = 0; temp->connectedPlaces[i]; i++)
		{
			if temp->connectedPlaces[i]->visited ==
		}
	}

	while ((temp = dequeue(q)))
		printf("%s\n", temp->name);
	return -1.0;
}
