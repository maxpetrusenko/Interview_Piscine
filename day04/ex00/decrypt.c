/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrypt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 11:43:16 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/24 12:19:44 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

char *getSum(char *a, char *b)
{
	int add = 0;
	for(int i = 5; i >= 0; i--)
	{
		if (a[i] == '0' && b[i] == '0')
		{
			a[i] = add + '0';
			add = 0;
		}
		else if ((a[i] == '1' & b[i] == '0') || (a[i] == '0' && b[i] == '1'))
		{
			if (add)
			{
				a[i] = '0';
				add = 1;
			}
			else
			{
				a[i] = '1';
				add = 0;
			}

		}
		else
		{
			a[i] = add + '0';
			add = 1;
		}
	}
	return a;
}

int toInt(char *bits)
{
 	//return (int) strtol(bits, NULL, 2); 
    int res = 0;
    int d = 32;
    for (int i = 0;i < 6; i++)
	{
        res += d * (bits[i] - '0');
		d /=2;
	}
    return res;
}
