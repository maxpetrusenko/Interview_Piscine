/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpNephew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 20:59:02 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/27 20:59:04 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double probaNephewWillLive(int nStairs, int nPunch, int nephewStair)
{
    if (!nStairs || !nPunch || !nephewStair)
        return 1;
    double total = 1;
    double res = (double)(nStairs - nephewStair)/nStairs;
    int i = 0;
    int j = 0;
    while (i <= nPunch)
    {
        while (j < nStairs - nephewStair)
        {
            res += (nStairs  -  nephewStair )/nStairs + i;
            j++;
        }
        i++;
        total *= res / i;
    }
    return total;
}
