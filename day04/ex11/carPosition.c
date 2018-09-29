/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carPosition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 21:56:14 by jaleman           #+#    #+#             */
/*   Updated: 2018/09/24 21:07:10 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <math.h>

int			carPosition(unsigned int parkingRow)
{
	if (parkingRow != 0 && (!(parkingRow & (parkingRow - 1))))
	{
		return log2(parkingRow);
	}
	return -1;
}
