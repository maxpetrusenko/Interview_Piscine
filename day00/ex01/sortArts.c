/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortArts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:36:30 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/17 20:17:40 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	swap(struct s_art **arts, int i, int j)
{
	struct	s_art	*tmp;

	tmp = arts[i];
	arts[i] = arts[j];
	arts[j] = tmp;
}

static int	partition(struct s_art **arts, int low, int high)
{
	char	*pivot;	
	int 	i = low - 1;
	pivot = arts[high]->name;

	for (int j = low; j <= high - 1; j++)
	{
		if (strcmp(arts[j]->name,pivot) <= 0)
		{
			i++;
			swap(arts, i, j);
		}
	}
	swap(arts, i + 1, high);
	return (i + 1);
}

void		quickSort(struct s_art **arts, int low, int high)
{
	int part_index = 0;

	if (low < high)
	{
		part_index = partition(arts, low,high);
		quickSort(arts,low, part_index - 1);
		quickSort(arts, part_index, high);
	}
}

void		sortArts(struct s_art **arts)
{
	int i = 0;
	while (arts[i])
		i++;
	return quickSort(arts, 0, i-1);
}

