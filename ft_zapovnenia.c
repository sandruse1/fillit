/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zapovnenia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 16:21:40 by sandruse          #+#    #+#             */
/*   Updated: 2017/02/12 18:33:45 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

void	ft_delete(char **pole, int j)
{
	int r;
	int c;

	r = 0;
	while (pole[r] != NULL)
	{
		c = 0;
		while (pole[r][c])
		{
			if (pole[r][c] > 64 + j)
				pole[r][c] = '.';
			c++;
		}
		r++;
	}
}

void	ft_zapus(char **p, int r, int c, char *t)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (t[i])
	{
		if (t[i] == '\n')
		{
			r++;
			c = c - count;
			count = 0;
		}
		else if (t[i] == '.')
		{
			count++;
			c++;
		}
		else if (t[i] > 46)
		{
			p[r][c++] = t[i];
			count++;
		}
		i++;
	}
}

int		ft_ok(char **p, int r, int c, char *t)
{
	int i;
	int flag;
	int count;

	flag = 1;
	i = -1;
	count = 0;
	while (t[++i] && flag == 1 && p[r] != NULL)
		if (t[i] == '\n')
		{
			r++;
			c = c - count;
			count = 0;
		}
		else if ((p[r][c] == '.' || (p[r][c] > 46 && t[i] == '.')))
		{
			c++;
			count++;
		}
		else
			flag = 0;
	if (p[r] == NULL)
		flag = 0;
	return (flag);
}

int		ft_try(char **pole, char **terminos, int j)
{
	int flag;
	int c;
	int r;

	flag = 0;
	r = 0;
	while (pole[r] != NULL && flag == 0 && terminos[j] != NULL)
	{
		c = 0;
		while (pole[r][c] && flag == 0)
		{
			if (ft_ok(pole, r, c, terminos[j]))
			{
				ft_zapus(pole, r, c, terminos[j]);
				if (terminos[j + 1] == NULL)
					flag = 1;
				else if (!(flag = ft_try(pole, terminos, j + 1)))
					ft_delete(pole, j);
			}
			c++;
		}
		r++;
	}
	return (flag);
}

int		ft_zapovnenia(char **pole, char **terminos)
{
	return (ft_try(pole, terminos, 0));
}
