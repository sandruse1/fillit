/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 19:38:53 by sandruse          #+#    #+#             */
/*   Updated: 2017/02/05 15:40:27 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "tetris.h"
#include <unistd.h>

int			ft_mistake(char *buf, int ret)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (i < ret)
	{
		if (buf[i] == '\n' && buf[i + 1] == '\n' && (buf[i + 2] == '\n'
					|| buf[i + 2] == '\0'))
			return (0);
		if (buf[i] != '\n' && buf[i] != '.' && buf[i] != '#')
			return (0);
		i++;
		if (buf[i] == '\n')
			k++;
		if (buf[i] == '\n' && k == 5 && buf[i - 1] != '\n')
			return (0);
		if (k == 5)
			k = 0;
	}
	return (1);
}

char		*ft_read(char *s, int fd)
{
	int		ret;
	int		i;
	char	*buf;

	i = 0;
	buf = (char*)malloc(sizeof(char) * 547);
	ret = read(fd, buf, 547);
	s = (char*)malloc(sizeof(char) * ret);
	if (!s || ret > 546 || (ft_mistake(buf, ret)) == 0 || ret < 20)
		return (NULL);
	while (i < ret)
	{
		s[i] = buf[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char		*ft_open_read(char *s)
{
	int		fd;
	char	*str;

	str = NULL;
	fd = open(s, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("error");
		return (NULL);
	}
	str = ft_read(str, fd);
	if (close(fd) == -1)
	{
		ft_putendl("error");
		return (NULL);
	}
	return (str);
}
