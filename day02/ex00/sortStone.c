/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortStone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 08:50:46 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/19 11:44:56 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(struct s_stone **array, int size)
{
	struct s_stone *temp;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (array[i]->size < array[j]->size)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}

int 	getGroup(struct s_stone *stone, struct s_stone **array)
{
	int num = 0 ;
	int groupSize = 0;

	while (stone)
	{
		if (stone->size != groupSize)
		{
			if (array)
				array[num] = stone;
			groupSize = stone->size;
			num++;
		}
		stone = stone->next;
	}
	return num;
}

struct	s_stone *lastStone(struct s_stone *last)
{
	while (last->next && last->next->size == last->size)
		last = last->next;
	return (last);
}

struct s_stone *sortGroup(struct s_stone **array, int size)
{
	struct s_stone *node;

	for (int i = 0; i < size; i++)
	{
		node = lastStone(array[i]);
		if (i == size -1)
			node->next = NULL;
		else
			node->next = array[i + 1]; 
	}
	return array[0];
}

void	sortStones(struct s_stone **stone)
{
	int group = getGroup(*stone, NULL);
	struct s_stone *array[group];

	getGroup(*stone, array);
	bubbleSort(array, group);
	*stone = sortGroup(array, group);
}
