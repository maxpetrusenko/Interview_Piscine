/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howManyJesus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 10:44:55 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/18 12:46:49 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>

int hash(char *string, int start, int end)
{
	int i = start;
	int total = 0;

	while (i <= end)
	{
		total += string[i];
		i++;
	}
	return (total);
}

int howManyJesus(char *bible, char *jesus)
{
	int totalJesus = 0;
	int jesus_len = strlen(jesus);
	int jesus_hash = hash(jesus, 0, jesus_len - 1);
	int curr_hash = 0;
	int l = 0;
	int r = 0;

	while(*(bible + r) && r < jesus_len)
	{
		curr_hash += bible[r];
		r++;
	}
	r--;
	while (*(bible + r))
	{
		if (jesus_hash == curr_hash)
		{
			if (!strncmp(jesus, bible + l, jesus_len))
				totalJesus++;
			l++;
			r++;
		}
		else
		{
			l++;
			r++;
			curr_hash -= bible[l - 1];
			curr_hash += bible[r];
		}
	}
	return (totalJesus);
}
