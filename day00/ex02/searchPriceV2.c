/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 20:24:07 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/17 21:01:31 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>

int binarySearch(struct s_art **arts, int low,int high, char *name)
{
	int mid;

	if (low < high)
	{
		mid = (high - low) / 2 +low;
		if (strcmp(arts[mid]->name, name) == 0)
			return (arts[mid]->price);
		if (strcmp(arts[mid]->name, name) > 0)
			return (binarySearch(arts, low, mid - 1, name));
		if (strcmp(arts[mid]->name, name) < 0)
			return (binarySearch(arts, mid + 1, high, name));
	}
	return (-1);
}

int	searchPrice(struct s_art **arts, int n, char *name)
{
	return (binarySearch(arts, 0, n - 1, name));
}
