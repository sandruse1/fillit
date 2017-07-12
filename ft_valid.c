/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:55:55 by sandruse          #+#    #+#             */
/*   Updated: 2017/01/16 11:11:37 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

int		math(char *str)
{
	int i;
	int n;
	int s;
	int d;

	i = 0;
	n = 4;
	s = 4;
	d = 12;
	while (str[i])
	{
		if (str[i] == '\n' || str[i + 1] == '\0')
			n--;
		if (str[i] == '.')
			d--;
		if (str[i] == '#')
			s--;
		i++;
	}
	if (n || s || d)
		return (0);
	return (1);
}

int		blok(char *s)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '#' && s[i + 1] == '#')
			count++;
		if (s[i] == '#' && s[i + 5] == '#')
			count++;
		if (s[i] == '#' && s[i - 1] == '#')
			count++;
		if (s[i] == '#' && s[i - 5] == '#')
			count++;
		if (s[i] == '\n')
			if (!(i == 4 || i == 9 || i == 14 || i == 19))
				return (0);
		i++;
	}
	if (count == 6 || count == 8)
		return (1);
	else
		return (0);
}

int		ft_valid(char **matrix)
{
	int j;

	j = 0;
	while (matrix[j] != NULL)
	{
		if (math(matrix[j]) == 0)
			return (0);
		if (blok(matrix[j]) == 0)
			return (0);
		j++;
	}
	return (1);
}
