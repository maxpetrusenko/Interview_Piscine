/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:09:48 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/26 19:45:00 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdio.h>

void	swap(char *x, char *y) {
    char temp = *x; 
    *x = *y; 
    *y = temp; 
} 

void	permute(char *a, int l, int r)
{
   int i = 0;
   if (l == r)
	   printf("%s\n", a);
   else
   {
	   for (i = l; i <= r; i++)
	   {
		   swap((a + l), (a + i));
		   permute(a, l + 1, r);
		   swap((a + l), (a + i));
	   }
   }
}

void	printPermutations(char *str) 
{
	if (!str) 
		return ;
	permute(str, 0 , strlen(str) - 1);
}
