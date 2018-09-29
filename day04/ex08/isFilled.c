/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isFilled.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 17:11:19 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/24 19:55:34 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//the idea here is to check of (index & index +1)

int isFilled(unsigned int parkingRow)
{
	return parkingRow && (parkingRow & (-(~parkingRow))) == 0;	
}
