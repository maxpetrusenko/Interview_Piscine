/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piano.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 12:30:13 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/25 13:36:33 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

int **pianoDecompress(struct s_bit *bit, int l)
{
	int **arr = malloc(sizeof(int *) *bit->n);
	for (int i = 0; i < bit->n; i++)
	{
		arr[i] = malloc(sizeof(int)* l-1);
		int j = 0;
		for (j = 0; bit->arr[i] -1; j++)
			bit->arr[i] = bit->arr[i] >> 1;
		arr[i][j] = 1;
	}
	return arr;
}
