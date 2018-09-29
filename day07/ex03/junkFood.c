/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   junkFood.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 20:31:39 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/28 20:31:41 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdlib.h>

struct s_sellers *closestSellers(struct s_graph *parisPlaces, char *youAreHere)
{
    int dist = 0;
	int count = 0;
	struct s_node *temp;
	struct s_queue *que = queueInit();
	struct s_queue *cereal = queueInit();
	struct s_node *begin = NULL;

	for (int i = 0; parisPlaces->places[i]; i++)
	{
		if (strcmp(youAreHere, parisPlaces->places[i]->name) == 0)
		{
			begin = parisPlaces->places[i];
			break;
		}
	}
	if (!begin)
		return NULL;
	enqueue(que, begin);
	enqueue(que, NULL);
	while (que->first)
	{
		while ((temp = dequeue(que)))
		{
			temp->visited = 1;
			if (temp->hasCerealBar)
			{
				count++;
				enqueue(cereal, temp);
			}
			else
			{
				for (int j = 0; temp->connectedPlaces[j]; j++)
					if (temp->connectedPlaces[j]->visited != 1)
					{
						temp->connectedPlaces[j]->visited = 1;
						enqueue(que, temp->connectedPlaces[j]);
					}
			}
		}
		enqueue(que, NULL);
		if (count)
			break;
		dist++;
	}
	struct s_sellers *sellers = malloc(sizeof(struct s_sellers));
	sellers->distance = dist;
	sellers->placeNames = malloc(sizeof(char *) * count + 1);
	for (int i = 0; i < count; i++)
		sellers->placeNames[i] = dequeue(cereal)->name;
	sellers->placeNames[count] = NULL;
	return sellers;
}
