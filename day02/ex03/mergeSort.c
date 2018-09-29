/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 17:06:25 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/19 17:59:56 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int getLength(struct s_player **players)
{
	int i = 0;

	while(players[i])
		i++;
	return i;
}

void	merge(struct s_player **players, int l, int m, int r)
{
	int L = m - l + 1;
	int R = r - m;
	int i,j,k;
	struct s_player *Lplayers[L];
	struct s_player *Rplayers[R];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < L; i++)
		Lplayers[i] = players[l + i];
	for (j = 0; j < R; j++)
		Rplayers[j] = players[m + 1 + j];

	i = j = 0;
	k = l;
	while (i < L && j < R)
	{
		if (Lplayers[i]->score <= Rplayers[j]->score)
		{
			players[k] = Lplayers[i];
			i++;
		}
		else
		{
			players[k] = Rplayers[j];
			j++;
		}
		k++;
	}
	/* Copy the remaining elements of L[], if there are any */
	while (i < L)
	{
		players[k] = Lplayers[i];
		i++;
		k++;
	}
 	/* Copy the remaining elements of R[], if there are any */
	while (j < R)
	{
		players[k] = Rplayers[j];
		j++;
		k++;
	}
}

void	mergeSorting(struct s_player **players, int l, int r)
{
	int m = l + (r - l)/2;
	if (l < r)
	{
		mergeSorting(players,l,m);
		mergeSorting(players,m+1,r);
		merge(players,l,m,r);
	}
}

struct s_player **mergeSort(struct s_player **players)
{
	mergeSorting(players, 0, getLength(players) - 1);
	return (players);
}
