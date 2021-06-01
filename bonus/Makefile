# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/28 17:14:08 by mmehran           #+#    #+#              #
#    Updated: 2021/06/01 14:20:56 by mmehran          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

UTILS_OBJS = ../utils/ft_atoi.o ../utils/ft_itoa.o
SERVER_OBJS = server_bonus.o
CLIENT_OBJS = client_send_bonus.o client_bonus.o
OBJS = $(UTILS_OBJS) $(SERVER_OBJS) $(CLIENT_OBJS)

TARGETS = server client

all: $(TARGETS)

client: $(UTILS_OBJS) $(CLIENT_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

server: $(UTILS_OBJS) $(SERVER_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(OBJS)
	$(RM) $(TARGETS)

re: clean all

.PHONY: all clean fclean re
