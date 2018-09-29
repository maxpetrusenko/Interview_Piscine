/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rightmostCar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 22:08:51 by jaleman           #+#    #+#             */
/*   Updated: 2018/09/24 21:42:44 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <math.h>

int			rightmostCar(unsigned int parkingRow)
{
	if (parkingRow != 0)
		return log2(parkingRow&-parkingRow);
	return -1;
}
