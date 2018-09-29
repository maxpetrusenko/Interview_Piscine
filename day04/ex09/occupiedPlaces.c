/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   occupiedPlaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 20:05:21 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/24 20:09:43 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//O(m) time, m - occupied spaces

int occupiedPlaces(unsigned int parkingRow)
{
	int i = 0;
	for (i = 0; parkingRow; i++)
		parkingRow = parkingRow & (parkingRow -1);
	return i;
}
