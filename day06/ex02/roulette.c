/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roulette.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 12:39:21 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/27 12:49:57 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double probabilityWin(double initDollars, double wantedDollars, int nbGame)
{
	if (nbGame < 0 || initDollars == 0)
		return 0;
	if (initDollars >= wantedDollars)
		return 1;
	else
		return (18 * probabilityWin(2 *initDollars, wantedDollars, nbGame - 1) + probabilityWin(initDollars / 2, wantedDollars, nbGame - 1))/37;
}
