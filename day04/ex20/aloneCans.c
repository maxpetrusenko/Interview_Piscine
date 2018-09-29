/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aloneCans.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:26:38 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/25 14:37:54 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void	aloneCans(int *arr, int n)
{
	int can = 0;
	int can2 = 0;
	int xor = 0;
	for (int i = 0; i< n; i++)
		xor ^= arr[i];
	for (int i = 0; i < n; i++)
		if (arr[i] & xor & ~(xor -1)) 
			can ^= arr[i];
		else
			can2 ^= arr[i];
	printf("%d\n%d\n", can,can2);
}
