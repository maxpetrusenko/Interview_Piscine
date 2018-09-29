/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createBST.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 19:27:20 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/28 19:35:37 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

struct s_node *create(int value)
{
	struct s_node *tmp = malloc(sizeof(struct s_node));
	tmp->value = value;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

struct s_node *insert(int *arr, int left, int right)
{
	struct s_node *n;

	int mid = left + (right - left) / 2;
	if (left > right)
		return NULL;
	n = create(arr[mid]);
	n->left = insert(arr, left, mid - 1);
	n->right = insert(arr, mid + 1, right);
	return n;
}

struct s_node *createBST(int *arr, int n)
{
	if (n < 1 || !arr)
		return NULL;
	return insert(arr, 0, n - 1);
}
