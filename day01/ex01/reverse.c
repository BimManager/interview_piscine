/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:29:20 by kkozlov           #+#    #+#             */
/*   Updated: 2020/02/25 10:40:05 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "header.h"

static void	xprint_reverse(struct s_node *lst, struct s_node *head)
{
	if (!lst)
		return ;
	xprint_reverse(lst->next, head);
	printf("%s", lst->word);
	if (lst != head)
		printf(" ");
}

void		printReverse(struct s_node *lst)
{
	xprint_reverse(lst, lst);
}
