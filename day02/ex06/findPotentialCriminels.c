/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findPotentialCriminels.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 21:09:43 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/20 11:38:13 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

int getLen(struct s_criminal **criminals, int *len)
{
	int max = 0;
	int i = 0;

	while (criminals[i])
	{
		if (criminals[i]->description > max)
			max = criminals[i]->description;
		i++;
	}
	*len = i;
	return max;
}

void	countSort(struct s_criminal **criminals, int ten, int n)
{
	int res[10] = {0};
	int i,j;
	struct s_criminal *sorted[n];

	for (i = 0; i < n; i++)
	{
		int digit = (criminals[i]->description / ten) % 10;
		res[digit]++;
	}
	for (i = 1; i < 10; i++)
		res[i] += res[i - 1];
	for (i = n - 1; i >= 0; i--)
	{
		j = (criminals[i]->description / ten) % 10;
		sorted[res[j] -1] = criminals[i];
		res[j]--;
	}
	for (i = 0; i < n; i++)
		criminals[i] = sorted[i];
}

int binarySearch(struct s_criminal **criminals, int low, int high, int desc)
{
	int i;
	int count = high - low;
	int step;

	while (count>0)
	{
		i = low;
		step = count / 2;
		i += step;
		if (criminals[i]->description < desc)
		{
			low = ++i;
			count -= step + 1;
		}
		else
			count = step;
	}
	if (low == high)
		return -1;
	return low;
}

int getDescription(struct s_info *info)
{
	if (!info)
		return 0;
	return info->gender * 1000000 +
		info->height * 100000 +
		info->hairColor * 10000 +
		info->eyeColor * 1000 +
		info->glasses * 100 +
		info->tattoo * 10 +
		info->piercing * 1;
}

void sortCriminals(struct s_criminal **criminals)
{
	int len;
	int max = getLen(criminals, &len);

	for (int i = 1; max / i > 0; i *= 10)
		countSort(criminals, i, len);
}

struct s_criminal **findPotentialCriminals(struct s_criminal **criminals, struct s_info *info)
{
	int len;
	int upper;
	int desc = getDescription(info);
	int found;
	int i;
	struct s_criminal **result;

	getLen(criminals, &len);
	found = binarySearch(criminals, 0, len, desc);
	if (found == -1)
		return NULL;
	upper = found + 1;
	while (criminals[upper] && criminals[upper]->description == desc)
		upper++;
	result = malloc(sizeof(struct s_criminal *) * (upper - found + 1));
	i = 0;
	while (found != upper)
		result[i++] = criminals[found++];
	result[i] = NULL;
	return result;
}
