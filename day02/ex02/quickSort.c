/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 16:05:35 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/19 16:56:29 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	swap(struct s_player **players, int i, int j)
{
	struct	s_player	*tmp;

	tmp = players[i];
	players[i] = players[j];
	players[j] = tmp;
}

static int	partition(struct s_player **players, int low, int high)
{
	struct s_player *pivot;
	int 	i = low - 1;
	pivot = players[high];

	for (int j = low; j <= high - 1; j++)
	{
		if (players[j]->score <= pivot->score)
		{
			i++;
			swap(players, i, j);
		}
	}
	swap(players, i + 1, high);
	return (i + 1);
}

void		quickSorting(struct s_player **players, int low, int high)
{
	int part_index = 0;

	if (low < high)
	{
		part_index = partition(players, low,high);
		quickSorting(players,low, part_index - 1);
		quickSorting(players, part_index, high);
	}
}

void		quickSort(struct s_player **players)
{
	int i = 0;
	while (players[i])
		i++;
	return quickSorting(players, 0, i-1);
}
