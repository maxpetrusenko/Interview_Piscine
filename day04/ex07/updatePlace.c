/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updatePlace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 17:09:27 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/24 17:09:58 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned int updatePlace(unsigned int parkingRow, int pos, int value)
{
	if (value != 0)
		parkingRow |= (1 << pos);
	else
		parkingRow &= ~(1 << pos);
	return parkingRow;
}
