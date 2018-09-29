/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 12:03:01 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/24 13:05:19 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

char *getNeg(char *a)
{
	for (int i = 0; i < 4; i++)
		a[i] = (a[i] == '1') ? '0': '1';
	return a;
}

char *getAnd(char *a,char *b)
{
	a = (a[0] == '~') ? getNeg(a+1) : a;
	b = (b[0] == '~') ? getNeg(b+1) : b;
	for (int i = 0; i < 4; i++)
		a[i] = (a[i] == '0'|| b[i] == '0') ? '0': a[i];
	return a;
}

char *getOr(char *a,char *b)
{
	a = (a[0] == '~') ? getNeg(a + 1) : a;
	b = (b[0] == '~') ? getNeg(b + 1) : b;
	for (int i = 0; i < 4; i++)
		a[i] = (a[i] == '1'|| b[i] == '1') ? '1': a[i];
	return a;
}

int toInt(char *bits)
{
  return (int) strtol(bits, NULL, 2);
}
