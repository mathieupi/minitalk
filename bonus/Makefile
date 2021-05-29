# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/28 17:14:45 by mmehran           #+#    #+#              #
#    Updated: 2021/05/29 02:02:02 by mmehran          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SERVER_OBJS = server_bonus.o
CLIENT_OBJS = client_bonus.o ft_atoi.o
OBJS = $(SERVER_OBJS) $(CLIENT_OBJS)


TARGETS = server client

all: $(TARGETS)

client: $(CLIENT_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

server: $(SERVER_OBJS)
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
