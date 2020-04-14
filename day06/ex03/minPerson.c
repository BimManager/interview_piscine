/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minPerson.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:39:26 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/05 09:50:57 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	minPersons(int elements, int minPercentage)
{
	int		cur_percentage;
	int		n_people;
	int		i;
	double	temp;

	if (0 > minPercentage
		|| 100 < minPercentage)
		return (-1);
	n_people = 0;
	cur_percentage = 0;
	temp = 0;
	while (cur_percentage < minPercentage)
	{
		++n_people;
		temp = 1.0;
		i = -1;
		while (++i < n_people)
			temp *= (double)(elements - i) / elements;
		cur_percentage = (1.0 - temp) * 100;
	}
	return (n_people);
}
