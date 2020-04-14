/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 08:52:45 by kkozlov           #+#    #+#             */
/*   Updated: 2020/02/24 09:13:57 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "header.h"

int		searchPrice(struct s_art **arts, char *name)
{
	int	i;

	i = -1;
	while (arts[++i])
		if (0 == strcmp(arts[i]->name, name))
			return (arts[i]->price);
	return (-1);
}
