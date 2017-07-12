/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 11:13:09 by sandruse          #+#    #+#             */
/*   Updated: 2017/01/21 10:26:22 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIS_H
# define TETRIS_H
# include <string.h>
# include <stdlib.h>

char	*ft_open_read(char *s);
int		ft_valid(char **matrix);
char	**ft_delim(char *s);
char	**ft_trim(char **matrix);
char	**ft_cut(char **matrix);
size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putendl(char const *s);
char	*ft_strstr(const char *big, const char *little);
char	*ft_strcpy(char *dst, const char *src);
void	ft_field(char **terminos, int i, int k);
int		ft_zapovnenia(char **pole, char **terminos);
void	ft_print_field(char **pole);

#endif
