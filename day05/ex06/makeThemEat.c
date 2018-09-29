/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makeThemEat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 17:15:55 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/26 19:41:41 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

int recurse(t_people **people, int nb, int nbTable, int totalTime, int *tab)
{
	if (!people[nb])
		return (1);
	for (int i = 0; i < nbTable; i++) 
	{
		if (tab[i] + people[nb]->time <= totalTime)
		{
			tab[i] += people[i]->time;
			if (recurse(people, i + 1, nbTable, totalTime, tab))
					return (1);
			tab[i] -= people[i]->time;
		}
		else
			return (0);
	}
	return (0);
}

int isPossible(t_people **people, int nbTable, int totalTime)
{
	int *tab = malloc(sizeof(int) * nbTable);
	int ret = recurse(people, 0, nbTable, totalTime, tab);
	free(tab);
	return ret;
}
