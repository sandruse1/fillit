/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 15:20:55 by sandruse          #+#    #+#             */
/*   Updated: 2017/01/14 16:59:11 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

char		*ft_56(char *matrix, int k)
{
	char *cut;

	cut = (char*)malloc(sizeof(char) * k + 1);
	if (k == 5)
	{
		if (ft_strcmp(matrix, "##.##\0") == 0)
			ft_strcpy(cut, ".##\n##.\0");
		if (ft_strcmp(matrix, "#.###\0") == 0)
			ft_strcpy(cut, "..#\n###\0");
		if (ft_strcmp(matrix, "###.#\0") == 0)
			ft_strcpy(cut, "###\n#..\0");
	}
	if (k == 6)
	{
		if (ft_strcmp(matrix, "##..##\0") == 0)
			ft_strcpy(cut, "##\n##\0");
		if (ft_strcmp(matrix, "#..###\0") == 0)
			ft_strcpy(cut, ".#.\n###\0");
		if (ft_strcmp(matrix, "###..#\0") == 0)
			ft_strcpy(cut, "###\n.#.\0");
	}
	return (cut);
}

char		*ft_4710(char *matrix, int k)
{
	char *cut;

	cut = (char*)malloc(sizeof(char) * k + 1);
	if (k == 7)
	{
		if (ft_strcmp(matrix, "##...##\0") == 0)
			ft_strcpy(cut, "##.\n.##\0");
		if (ft_strcmp(matrix, "#...###\0") == 0)
			ft_strcpy(cut, "#..\n###\0");
		if (ft_strcmp(matrix, "###...#\0") == 0)
			ft_strcpy(cut, "###\n..#\0");
	}
	else if (k == 10)
	{
		if (ft_strcmp(matrix, "#...##...#\0") == 0)
			ft_strcpy(cut, "#.\n##\n.#\0");
		if (ft_strcmp(matrix, "#...#...##\0") == 0)
			ft_strcpy(cut, "#.\n#.\n##\0");
		if (ft_strcmp(matrix, "##...#...#\0") == 0)
			ft_strcpy(cut, "##\n.#\n.#\0");
	}
	else
		ft_strcpy(cut, "####\0");
	return (cut);
}

char		*ft_8913(char *matrix, int k)
{
	char *cut;

	cut = (char*)malloc(sizeof(char) * k + 1);
	if (k == 13)
		ft_strcpy(cut, "#\n#\n#\n#\0");
	else if (k == 8)
		ft_strcpy(cut, ".#\n##\n#.\0");
	else if (k == 9)
	{
		if (ft_strcmp(matrix, "#..##...#\0") == 0)
			ft_strcpy(cut, ".#\n##\n.#\0");
		if (ft_strcmp(matrix, "#...##..#\0") == 0)
			ft_strcpy(cut, "#.\n##\n#.\0");
		if (ft_strcmp(matrix, "#...#..##\0") == 0)
			ft_strcpy(cut, ".#\n.#\n##\0");
		if (ft_strcmp(matrix, "##..#...#\0") == 0)
			ft_strcpy(cut, "##\n#.\n#.\0");
	}
	return (cut);
}

void		ft_toletter(char **cut)
{
	int		i;
	int		j;
	char	k;

	i = 0;
	j = 0;
	k = 'A';
	while (cut[j] != NULL)
	{
		while (cut[j][i])
		{
			if (cut[j][i] == '#')
				cut[j][i] = k;
			i++;
		}
		i = 0;
		j++;
		k++;
	}
}

char		**ft_cut(char **matrix)
{
	int		k;
	int		j;
	char	**cut;

	j = 0;
	while (matrix[j] != NULL)
		j++;
	cut = (char**)malloc(sizeof(char*) * j + 1);
	j = 0;
	while (matrix[j] != NULL)
	{
		k = ft_strlen(matrix[j]);
		if (k == 5 || k == 6)
			cut[j] = ft_56(matrix[j], k);
		else if (k == 4 || k == 7 || k == 10)
			cut[j] = ft_4710(matrix[j], k);
		else if (k == 8 || k == 9 || k == 13)
			cut[j] = ft_8913(matrix[j], k);
		j++;
	}
	cut[j] = NULL;
	ft_toletter(cut);
	return (cut);
}
