# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/28 20:33:58 by mmehran           #+#    #+#              #
#    Updated: 2021/05/25 10:51:57 by mmehran          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	$(AR) $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
