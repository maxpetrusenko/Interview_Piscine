/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:51:31 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/17 14:32:03 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	searchPrice(struct s_art **arts, char *name)
{
	int i = -1;

	while (arts[++i])
	{
		if (strcmp(arts[i]->name, name) == 0)
			return (arts[i]->price);
	}
	return (-1);
}

