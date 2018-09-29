/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createBST.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 13:14:12 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/20 13:14:14 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

struct s_node *newNode(int val)
{
    struct s_node *node = malloc(sizeof(struct s_node));
    node->value = val;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

struct s_node *sortedArrayToBST(int arr[], int start, int end)
{
    int mid = (start + end) / 2;
    struct s_node *node = newNode(arr[mid]);
    if (start > end) 
        return (NULL);
    node->left = sortedArrayToBST(arr, start, mid-1);
    node->right = sortedArrayToBST(arr, mid+1, end);

    return (node);
}

struct s_node *createBST(int *arr, int n)
{
	struct s_node *node = NULL;

	if (n <= 0)
		return NULL;
	return sortedArrayToBST(arr, 0, n - 1);
}
