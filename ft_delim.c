/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:41:59 by sandruse          #+#    #+#             */
/*   Updated: 2017/01/14 16:45:32 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

int		word_count(char const *s, char *c)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 1;
	while (s[j])
	{
		while (c[i] == s[j + i])
		{
			if (i == 1)
				k++;
			i++;
		}
		i = 0;
		j++;
	}
	return (k);
}

char	**copy(char **d, char const *s)
{
	int i;
	int j;
	int n;

	i = 0;
	j = 0;
	n = 0;
	while (s[i] != '\0')
	{
		while (s[i] == '\n')
			i++;
		d[j] = (char*)malloc(sizeof(char) * 21);
		if (!d[j])
			return (NULL);
		while (n < 20)
		{
			d[j][n++] = s[i++];
		}
		d[j][n] = '\0';
		n = 0;
		j++;
	}
	d[j] = NULL;
	return (d);
}

char	**ft_delim(char *s)
{
	char **d;
	char *c;

	c = "\n\n";
	if (!s)
		return (0);
	d = (char**)malloc(sizeof(char*) * word_count(s, c) + 1);
	if (!d)
		return (NULL);
	d = copy(d, s);
	return (d);
}
