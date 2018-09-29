/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leftmostCar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 21:21:42 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/24 21:54:42 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int leftmostCar(unsigned int parkingRow)
{
	int i = -1;
	for (i = -1; parkingRow; ++i)
		parkingRow >>=1;
	return i;
}
