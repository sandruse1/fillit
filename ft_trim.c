/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 18:12:03 by sandruse          #+#    #+#             */
/*   Updated: 2017/01/20 12:33:37 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

char		*zapus(char *dd, char const *s, int n, int j)
{
	int i;

	i = 0;
	dd = (char*)malloc(sizeof(char) * n + 1);
	if (dd == NULL)
		return (0);
	while (n > 0)
	{
		if (s[j] == '\n')
			j++;
		dd[i++] = s[j++];
		n--;
	}
	dd[i] = '\0';
	return (dd);
}

char		*rozmir(char *s, int i, int j)
{
	int		n;
	char	*d;

	d = NULL;
	n = 0;
	while (s[i] != '#')
		i++;
	j = i;
	while (s[i + 1])
	{
		if (s[i] == '\n')
			n--;
		n++;
		i++;
	}
	while (s[i] != '#')
	{
		if (s[i] == '\n')
			n++;
		i--;
		n--;
	}
	d = zapus(d, s, n, j);
	return (d);
}

char		**ft_trim(char **matrix)
{
	int		j;
	int		i;
	char	**trim;

	j = 0;
	i = 0;
	while (matrix[j] != NULL)
		j++;
	trim = (char**)malloc(sizeof(char*) * j + 1);
	j = 0;
	while (matrix[j] != NULL)
	{
		trim[j] = rozmir(matrix[j], i, 0);
		j++;
	}
	trim[j] = NULL;
	return (trim);
}
