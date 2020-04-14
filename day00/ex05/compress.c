/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:58:46 by kkozlov           #+#    #+#             */
/*   Updated: 2020/02/26 09:03:51 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "header.h"

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

int				dictInsert(struct s_dict *dict, char *key, int value)
{
	size_t			hsh;
	struct s_item	*item;

	if (!dict || !key)
		return (0);
	hsh = hash(key) % dict->capacity;
	item = malloc(sizeof(struct s_item));
	if (!item)
		return (0);
	item->key = strdup(key);
	item->next = NULL;
	item->value = value;
	if (!dict->items[hsh])
		dict->items[hsh] = item;
	else
	{
		item->next = dict->items[hsh];
		dict->items[hsh] = item;
	}
	return (1);
}

int				dictSearch(struct s_dict *dict, char *key)
{
	size_t			hsh;
	struct s_item	*it;

	if (!key)
		return (-1);
	hsh = hash(key) % dict->capacity;
	if (!(it = dict->items[hsh]))
		return (-1);
	while (it)
	{
		if (0 == strcmp(it->key, key))
			return (it->value);
		it = it->next;
	}
	return (-1);
}

static char		**headergen(struct s_dict *dict, int *total_len)
{
	char			**tab;
	struct s_item	*it;
	int				i;

	*total_len = 0;
	tab = malloc(256 * sizeof(void *));
	bzero(tab, 256 * sizeof(void *));
	i = -1;
	while (++i < dict->capacity)
	{
		if ((it = dict->items[i]))
		{
			while (it)
			{
				tab[it->value] = it->key;
				*total_len += strlen(tab[it->value]) + 1;
				it = it->next;
			}
		}
	}
	return (tab);
}

static char		*headerprep(char **tab, int total_len)
{
	char	*ret;
	char	*it;
	int		len;

	ret = malloc((total_len + 1) * sizeof(char));
	*ret = '<';
	it = ret + 1;
	while (*tab)
	{
		len = strlen(*tab);
		strncpy(it, *tab, len);
		it += len;
		*it++ = ',';
		tab++;
	}
	*(it - 1) = '>';
	*it = '\0';
	return (ret);
}

static char		*concat(char *header, char *text)
{
	char	*ret;
	int		hlen;
	int		tlen;

	hlen = strlen(header);
	tlen = strlen(text);
	ret = malloc((hlen + tlen + 1) * sizeof(char));
	strncpy(ret, header, hlen);
	strncpy(ret + hlen, text, tlen);
	ret[hlen + tlen] = '\0';
	return (ret);
}

/*
** its[0]: temp iterator
** its[1]: compressed string iterator
**
** data[0]: temp storage
** data[1]: initial length
** data[2]: new length
*/

static char		*textcompress(char *book, struct s_dict *dict)
{
	char	*its[2];
	char	*ret;
	char	buffer[256];
	int		data[3];

	data[1] = strlen(book);
	ret = malloc((data[1] + 1) * sizeof(char));
	its[1] = ret;
	data[2] = 0;
	while (*book)
	{
		while (!isalnum(*book))
		{
			*its[1]++ = *book++;
			++data[2];
		}
		its[0] = book;
		while (isalnum(*book))
			++book;
		data[1] = book - its[0];
		strncpy(buffer, its[0], data[1]);
		buffer[data[1]] = '\0';
		if (-1 != (data[0] = dictSearch(dict, buffer)))
		{
			*its[1]++ = '@';
			*its[1]++ = data[0] + 1;
			data[2] += 2;
		}
		else
		{
			strncpy(its[1], buffer, data[1]);
			its[1] += data[1];
			data[2] += data[1];
		}
	}
	ret[data[2]] = '\0';
	return (ret);
}

static void		tabfree(char ***xtab)
{
	char	**it;
	int		i;

	it = *xtab;
	i = -1;
	while (it[++i])
		free(it[i]);
	free(*xtab);
	*xtab = NULL;
}

char			*compress(char *book, struct s_dict *dict)
{
	char	*text;
	char	**tab;
	int		total_len;
	char	*header;
	char	*ret;

	text = textcompress(book, dict);
	tab = headergen(dict, &total_len);
	header = headerprep(tab, total_len);
	ret = concat(header, text);
	free(header);
	free(text);
	tabfree(&tab);
	return (ret);
}
