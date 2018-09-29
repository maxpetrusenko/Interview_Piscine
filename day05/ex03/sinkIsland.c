/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sinkIsland.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:32:37 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/26 19:45:30 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sinkIsland(int **map, int row, int col)
{
	if (row < 0 || col < 0 || !map[row] || map[row][col] == -1)
		return ;
	if (map[row][col] == 0)
		return ;
	map[row][col] = 0;	
	sinkIsland(map, row - 1, col);
	sinkIsland(map, row + 1, col);
	sinkIsland(map, row, col - 1);
	sinkIsland(map, row, col + 1);
}
