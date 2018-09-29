/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearPlace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 21:32:55 by jaleman           #+#    #+#             */
/*   Updated: 2018/09/24 16:15:51 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned int	clearPlace(unsigned int parkingRow, int pos)
{
	parkingRow &= ~(1 << pos);
	return (parkingRow);
}
