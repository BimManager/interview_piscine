/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findPalindrome.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:11:45 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/04 18:31:47 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

#include "header.h"

#include <stdio.h>

static char	*strrev(char *str)
{
	char	*rev;
	int		len;

	len = strlen(str);
	rev = malloc((len + 1) * sizeof(char));
	rev[len] = '\0';
	while (len--)
		rev[len] = *str++;
	return (rev);
}

static int	isPalindrome(char *str)
{
	char	*beg_it;
	char	*end_it;

	beg_it = str;
	end_it = str;
	while (*end_it)
		++end_it;
	while (--end_it > beg_it)
		if (*end_it != *beg_it++)
			return (0);
	return (1);
}

/*
**static int	isKPalindromeRec(char *str, int n, char *rev, int m)
**{
**	if (0 == n || 0 == m)
**		return (n + m);
**	if (str[n - 1] == rev[m - 1])
**		return (isKPalindromeRec(str, n - 1, rev, m - 1));
**	return (1 + XMIN(isKPalindromeRec(str, n - 1, rev, m),
**					 isKPalindromeRec(str, n, rev, m - 1)));
**}
*/

static int	**tabnew(int n, int m)
{
	int	**tab;
	int	i;

	tab = malloc((n + 1) * sizeof(void *));
	i = -1;
	while (++i <= n)
		tab[i] = malloc((m + 1) * sizeof(int));
	return (tab);
}

static void	tabdel(int ***tab, int n)
{
	int	i;

	i = -1;
	while (++i <= n)
		free((*tab)[i]);
	free(*tab);
	*tab = NULL;
}

static void	kPalindromePrint(int **tab, char *str, int n,
								char *rev, int m, char **it)
{
	if (0 == n || 0 == m)
		return ;
	if (str[n - 1] == rev[m - 1])
	{
		**it = str[n - 1];
		++*it;
		kPalindromePrint(tab, str, n - 1, rev, m - 1, it);
		return ;
	}
	if (tab[n - 1][m] > tab[n][m - 1])
		return (kPalindromePrint(tab, str, n - 1, rev, m, it));
	return (kPalindromePrint(tab, str, n, rev, m - 1, it));
}

static int	isKPalindrome(int **tab, char *str, int n, char *rev, int m)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= n)
	{
		j = -1;
		while (++j <= m)
		{
			if (0 == i || 0 == j)
				tab[i][j] = 0;
			else if (str[i - 1] == rev[j - 1])
				tab[i][j] = tab[i - 1][j - 1] + 1;
			else
				tab[i][j] = XMAX(tab[i - 1][j], tab[i][j - 1]);
		}
	}
	return (n - tab[n][m]);
}

static char	*composePalindrome(int **tab, char *str, int n, char *rev, int m)
{
	char	*palindrome;
	char	*it;

	palindrome = malloc((n + 1) * sizeof(char));
	palindrome[n] = '\0';
	it = palindrome;
	kPalindromePrint(tab, str, n, rev, m, &it);
	return (palindrome);
}

char		*findPalindrome(char *sequence, int nDelete)
{
	char	*rev;
	int		**tab;
	int		len;
	char	*palindrome;

	if (!sequence)
		return (NULL);
	if (!nDelete && isPalindrome(sequence))
		return (sequence);
	else if (!nDelete)
		return (NULL);
	rev = strrev(sequence);
	len = strlen(sequence);
	tab = tabnew(len, len);
	if (nDelete == isKPalindrome(tab, sequence, len, rev, len))
		palindrome = composePalindrome(tab, sequence, len, rev, len);
	else
		palindrome = NULL;
	free(rev);
	tabdel(&tab, len);
	return (palindrome);
}
