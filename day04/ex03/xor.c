/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 15:37:02 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/24 15:45:27 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

char *getXor(char *a, char *b)
{
	for(int i = 0; i < 6; i++)
	{	
		if (a[i] == b[i])
			a[i] = '0';
		else
			a[i] = '1';
	}
	return a;
}

int toInt(char *bits)
{
	return (int) strtol(bits, NULL, 2);
}
