/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printYoungest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 20:50:54 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/20 21:30:46 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>
int merge(int *arr, int low,int high)
{
	int mid;

				mid = (high - low) / 2 + low;
				if (arr[mid] == 0)
					return (arr[mid]);
				if (arr[mid] < low)
					return (merge(arr, low, mid - 1));
				if (arr[mid] >  high)
					return (merge(arr, mid + 1, high - 1));
	return arr[mid];
}

void printYoungest(int *ages, int length)
{
	printf("%d",merge(ages,0, length -1));
}