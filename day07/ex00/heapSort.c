/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapSort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 09:25:01 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/28 09:51:11 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>

void swap(struct s_art *a, struct s_art *b)
{
	struct s_art tmp = *a;
	*a = *b;
	*b = tmp;
}

void heapify(struct s_art **masterpiece, int n, int i)
{
	int biggest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;

	if (l < n && strcmp(masterpiece[l]->name,masterpiece[biggest]->name) > 0)
		biggest = l;
	if (r < n && strcmp(masterpiece[r]->name,masterpiece[biggest]->name) > 0)
		biggest = r;
	if (biggest  != i)
	{
		swap(masterpiece[i], masterpiece[biggest]);
		heapify(masterpiece, n , biggest);
	}
}


void heapSort(struct s_art **masterpiece, int n)
{
	for (int i = n/2 -1; i >= 0; i--)
		heapify(masterpiece, n, i);
	for (int i = n - 1;i >= 0; i--)
	{
		swap(masterpiece[0], masterpiece[i]);
		heapify(masterpiece, i, 0);
	}
}
