/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 18:09:46 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/19 19:25:13 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#define RANGE 16

void	countSort(unsigned char *utensils, int n)
{
	int res[RANGE] = {0};
	int i = 0;
	unsigned char *sorted = malloc(n);

	for (i = 0; i < n; i++)
		res[utensils[i] - 1]++;
	for (i = 1; i < RANGE; i++)
		res[i] += res[i - 1];
	for (i = 0; i < n; i++)
	{
		sorted[res[utensils[i] -1]] = utensils[i];
		res[utensils[i] - 1]--;
	}
	for (i = 0; i < n; i++)
		utensils[i] = sorted[i];
	free(sorted);
}
