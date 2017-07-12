/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 12:22:21 by sandruse          #+#    #+#             */
/*   Updated: 2017/01/21 10:27:49 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

int		main(int argc, char **argv)
{
	char	*copy;
	char	**matrix;
	char	**cut;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit [file name]");
		return (0);
	}
	copy = ft_open_read(argv[1]);
	if (copy == NULL)
	{
		ft_putendl("error");
		return (0);
	}
	matrix = ft_delim(copy);
	if (ft_valid(matrix) == 0)
	{
		ft_putendl("error");
		return (0);
	}
	matrix = ft_trim(matrix);
	cut = ft_cut(matrix);
	ft_field(cut, 0, 4);
	return (0);
}
