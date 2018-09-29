/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 11:57:45 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/20 12:54:29 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <math.h>
#include <limits.h>
#include <stdlib.h>

int getMin(struct s_node *node)
{
	int current;
	int left;
	int right;

	if (!node)
		return INT_MAX;
	current = node->value;
	left = getMin(node->left);
	right = getMin(node->right);
	if (current < left && current < right)
		return current;
	if (left < current && left < right)
		return left;
	return right;

	//  while (current->left != NULL) { 
    //		current = current->left; 
	//return (current->data); 
}

int getMax(struct s_node *node)
{
	int current;
	int left;
	int right;

	if (!node)
		return INT_MIN;
	current = node->value;
	left = getMax(node->left);
	right = getMax(node->right);
	if (current > left && current > right)
		return current;
	if (left > current && left > right)
		return left;
	return right;
}

int getSize(struct s_node *node)
{
	if (!node)
		return (0);
	return getSize(node->left) + getSize(node->right) + 1;
}

int getHeight(struct s_node *node)
{
	if (!node || (!node->left && !node->right))
		return (0);
	return (fmax(getHeight(node->left), getHeight(node->right)) + 1);
}

int checkBST(struct s_node *node)
{
	if (!node)
		return (1);
	if (node->left && getMax(node->left) > node->value)
		return 0;
	if (node->right && getMin(node->right) <= node->value)
		return 0;
	if (!checkBST(node->left) || !checkBST(node->right))
		return 0;
	return (1);
}

int isBalanced(struct s_node *node, int *h)
{	 
  int lh = 0, rh = 0;   
  
  /* l will be true if left subtree is balanced  
    and r will be true if right subtree is balanced */ 
  int l = 0, r = 0;

  if (node == NULL) 
  { 
    *h = 0; 
     return (1); 
  } 
  
  /* Get the heights of left and right subtrees in lh and rh  
    And store the returned values in l and r */    
  l = isBalanced(node->left, &lh); 
  r = isBalanced(node->right,&rh);
  *h = (lh > rh? lh: rh) + 1; 
  if ((lh - rh >= 2) || (rh - lh >= 2))
	return (0);
  else 
	return (l && r); 
}

struct s_info getInfo(struct s_node *node)
{
	struct s_info info;
	int height = 0;

	info.min = getMin(node);
	info.max = getMax(node);
	info.elements = getSize(node);
	info.height = getHeight(node);
	info.isBST = checkBST(node);
	info.isBalanced = isBalanced(node, &height);
	return (info);
}
