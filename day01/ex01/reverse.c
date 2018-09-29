/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 15:46:02 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/18 15:47:38 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void printReverse(struct s_node *lst)
{
	static int i = 0;
	if (!lst)
		return;
	i++;
	printReverse(lst->next);
	i--;
	printf("%s", lst->word);
	if (i)
		printf(" ");
	else
		printf("\n");
}
