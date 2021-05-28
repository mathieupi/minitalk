# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/28 17:14:45 by mmehran           #+#    #+#              #
#    Updated: 2021/05/28 17:14:45 by mmehran          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SERVER_OBJS = server_bonus.o
CLIENT_OBJS = client_bonus.o
OBJS = $(SERVER_OBJS) $(CLIENT_OBJS)

LIBFTPATH = ../libft

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
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFTPATH)
	$(RM) $(OBJS)
	$(RM) $(TARGETS)

re: clean all

.PHONY: all clean fclean re
