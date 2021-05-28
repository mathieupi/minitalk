# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/28 17:14:08 by mmehran           #+#    #+#              #
#    Updated: 2021/05/28 17:14:22 by mmehran          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SERVER_OBJS = server.o
CLIENT_OBJS = client.o
OBJS = $(SERVER_OBJS) $(CLIENT_OBJS)

LIBFTPATH = ./libft
BONUSPATH = ./bonus

TARGETS = server client

all: $(TARGETS)

client: $(CLIENT_OBJS)
	make -C $(LIBFTPATH)
	$(CC) $(CFLAGS) -o $@ $^ -L $(LIBFTPATH) -lft

server: $(SERVER_OBJS)
	make -C $(LIBFTPATH)
	$(CC) $(CFLAGS) -o $@ $^ -L $(LIBFTPATH) -lft

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	make clean -C $(LIBFTPATH)
	make clean -C $(BONUSPATH)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFTPATH)
	make fclean -C $(BONUSPATH)
	$(RM) $(OBJS)
	$(RM) $(TARGETS)

re: clean all

bonus:
	make -C $(BONUSPATH)

.PHONY: all clean fclean re bonus
