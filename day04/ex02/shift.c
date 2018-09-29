/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 13:10:52 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/24 15:29:55 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <string.h>

char *rightShift(char *bin, int k)
{
	int i = 0;
	if (k < 6)
		for (i = 5; i - k >= 0; i--)
			bin[i] = bin[i-k];
	for (i = 0; i < k && i < 6; i++)
		bin[i] = '1';
	return bin;

}

char *leftShift(char *bin, int k)
{
	int i = 0;
	for (i = 0; i + i < 6; i++)
		bin[i] = bin[i + k];
	for (i = 5; i >= 0 && k > 0; i--,k--)
		bin[i] = '0';
	return bin;
}

int toInt(char *bits)
{
	int result = 0;
	int shift = 1;
	int neg = (bits[0] == '1') ? 1 : 0;

	for (int i = 5;i >= 1; i--)
	{
		result = result + shift * ((bits[i] == '1') ^ neg);
		shift = shift << 1;
	}
	return (neg) ? -result -1 : result;
}
