/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPriceV2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 13:53:22 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/26 19:48:39 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

double	recursion(int pizzaSize, double *prices, double *b)
{
	double compare = 0;
	if (b[pizzaSize])
		return (b[pizzaSize]);
	b[pizzaSize] = prices[pizzaSize];
	for (int i = 1; i < pizzaSize; i++)
	{
		compare = recursion(i, prices, b) + recursion(pizzaSize - i, prices, b);
		if (compare > b[pizzaSize])
			b[pizzaSize] = compare;
	}
	return b[pizzaSize];
}

double optimizedBestPrice(int pizzaSize, double *prices)
{
	double *bestPrice = malloc(sizeof(double));
	return recursion(pizzaSize, prices, bestPrice);
}
