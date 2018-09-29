/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotspots.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 21:49:23 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/27 09:23:47 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int selectHotspots(struct s_hotspot **hotspots)
{
	int count = 1;
	int change = 0;
	for (int i = 1; hotspots[i]; i++)
	{
		if (hotspots[i]->pos - hotspots[i]->radius >= hotspots[change]->pos + hotspots[change]->radius)
		{
			count++;
			change = i;
		}
		else if (hotspots[change]->radius > 0)
			change = i;
	}
	return count;
}
