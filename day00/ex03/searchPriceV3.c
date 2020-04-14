/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:15:34 by kkozlov           #+#    #+#             */
/*   Updated: 2020/02/26 09:10:48 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

#include "header.h"

/*
** djb2
*/

size_t			hash(char *input)
{
	size_t	hash;
	int		c;

	hash = 5381;
	while ((c = *input++))
		hash = ((hash << 5) + hash) + c;
	return (hash);
}

struct s_dict	*dictInit(int capacity)
{
	struct s_dict	*dic;

	dic = malloc(sizeof(struct s_dict));
	if (!dic)
		return (NULL);
	dic->capacity = capacity;
	dic->items = malloc(capacity * sizeof(void *));
	bzero(dic->items, capacity * sizeof(void *));
	if (!dic->items)
	{
		free(dic);
		return (NULL);
	}
	return (dic);
}

struct s_item	*itemnew(const char *key, const struct s_art *value)
{
	struct s_item	*item;

	item = malloc(sizeof(struct s_item));
	if (!item)
		return (0);
	item->key = strdup(key);
	item->next = NULL;
	item->value = malloc(sizeof(struct s_art));
	item->value->price = value->price;
	item->value->name = strdup(value->name);
	return (item);
}

int				dictInsert(struct s_dict *dict, char *key, struct s_art *value)
{
	size_t			hsh;
	struct s_item	*item;

	if (!dict || !key || !value)
		return (0);
	hsh = hash(key) % dict->capacity;
	item = itemnew(key, value);
	if (!dict->items[hsh])
		dict->items[hsh] = item;
	else
	{
		item->next = dict->items[hsh];
		dict->items[hsh] = item;
	}
	return (1);
}

struct s_art	*dictSearch(struct s_dict *dict, char *key)
{
	size_t			hsh;
	struct s_item	*it;

	if (!key)
		return (NULL);
	hsh = hash(key) % dict->capacity;
	if (!(it = dict->items[hsh]))
		return (NULL);
	while (it)
	{
		if (0 == strcmp(it->key, key))
			return (it->value);
		it = it->next;
	}
	return (NULL);
}

int				searchPrice(struct s_dict *dict, char *name)
{
	struct s_art	*art;

	if ((art = dictSearch(dict, name)))
		return (art->price);
	return (-1);
}
