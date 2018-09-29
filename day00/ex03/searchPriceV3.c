/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 21:25:31 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/18 10:29:49 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

size_t	hash(char *input)
{
	size_t i = 0;
	while (*input)
	{
		i += *input;
		input++;
	}
	return (i);
}

struct	s_dict *dictInit(int capacity)
{
	struct s_dict *dict = (struct s_dict *)malloc(sizeof(struct s_dict));
	dict->capacity = capacity;
	dict->items = (struct s_item **)calloc(capacity, sizeof(struct s_item *));
	return (dict);
}

int	dictInsert(struct s_dict *dict, char *key, struct s_art *value)
{
	size_t k = hash(key) % dict->capacity;

	if (!dict->items[k])
	{
		dict->items[k] = (struct s_item *)malloc(sizeof(struct s_item));
		if (!dict->items[k])
			return (0);
		dict->items[k]->key = strdup(key);
		dict->items[k]->value = value;
		dict->items[k]->next = NULL;
	}
	else
	{
		struct s_item *tmp = dict->items[k];
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (struct s_item *)malloc(sizeof(struct s_item));
		tmp->next->key = strdup(key);
		if (!tmp->next || !tmp->next->key)
			return (0);
		tmp->next->value = value;
		tmp->next->next = NULL;
	}
	return (1);
}

struct s_art *dictSearch(struct s_dict *dict, char *key)
{
	int k = hash(key) % dict->capacity;
	struct s_item *tmp;

	tmp = dict->items[k];
	while (tmp)
	{
		if ((strcmp(key, tmp->value->name)) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return(NULL);
}

void		searchPrice(struct s_dict *dict, char *key)
{
	struct	s_art *test = dictSearch(dict, key);
	if (test)
		printf("%s\n", test->name);
	else
		printf("not found\n");
}
