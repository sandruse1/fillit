# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egaragul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/20 12:01:53 by egaragul          #+#    #+#              #
#    Updated: 2017/02/17 15:33:09 by sandruse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = ft_delim.c\
	  ft_cut.c\
	  ft_dodatkovi.c\
	  ft_field.c\
	  ft_open_read.c\
	  ft_trim.c\
	  ft_valid.c\
	  ft_zapovnenia.c\
	  fillit.c
GG = $(SRC:.c=.o)
HEAD = tetris.h
FLAG = -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(GG)

%.o: %.c $(HEAD)
	gcc $(FLAG) -o $@ $<

clean:
	rm -f $(GG)

fclean: clean
	rm -f $(NAME)

re: clean all
