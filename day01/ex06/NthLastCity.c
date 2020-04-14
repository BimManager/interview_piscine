/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NthLastCity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:16:42 by kkozlov           #+#    #+#             */
/*   Updated: 2020/02/25 17:23:54 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "header.h"

char	*NthLastCity(struct s_city *city, int n)
{
	struct s_city	*n_it;

	n_it = city;
	while (city && n--)
		city = city->next;
	if (n > 0)
		return (NULL);
	while ((city = city->next))
		n_it = n_it->next;
	return (n_it->name);
}
