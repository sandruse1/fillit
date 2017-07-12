/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 13:27:09 by sandruse          #+#    #+#             */
/*   Updated: 2017/01/20 13:25:55 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

char	**ft_create_field(char **pole, int size)
{
	int x;
	int y;

	y = 0;
	if (!(pole = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	while (y < size)
	{
		if (!(pole[y] = (char*)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		x = 0;
		while (x < size)
			pole[y][x++] = '.';
		pole[y++][x] = '\0';
	}
	pole[y] = NULL;
	return (pole);
}

void	ft_field(char **terminos, int i, int k)
{
	char	**pole;
	int		size;

	pole = NULL;
	size = 2;
	while (terminos[i] != NULL)
		i++;
	while (size * size < i * k)
		size++;
	pole = ft_create_field(pole, size);
	if (!(ft_zapovnenia(pole, terminos)))
		ft_field(terminos, 0, k + 1);
	else
		ft_print_field(pole);
}

void	ft_print_field(char **pole)
{
	int i;

	i = 0;
	while (pole[i] != NULL)
		ft_putendl(pole[i++]);
}
