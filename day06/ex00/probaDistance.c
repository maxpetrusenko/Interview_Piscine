/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   probaDistance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 21:23:05 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/26 21:41:13 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double probaDistance(int dist, int *locations, int n)
{
	double total = 0;
	double occured = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			total++;
			if (locations[i] - locations[j] > dist)
				occured++;
			if (locations[j] - locations[i] > dist)
				occured++;
		}
	}
	return occured / total;
}
