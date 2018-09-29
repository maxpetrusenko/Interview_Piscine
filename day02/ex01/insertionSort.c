/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionSort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 13:05:41 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/19 15:50:15 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	insertionSort(struct s_player **players)
{
	int			i, j;
	struct 		s_player	*player;

	i = 0;
	while (players[++i])
	{
		player = players[i];
		j = i;
		while (--j >= 0 && players[j]->score < player->score) {
			players[j + 1] = players[j];
		}
		players[j + 1] = player;
	}
}
