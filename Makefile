# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/28 17:14:08 by mmehran           #+#    #+#              #
#    Updated: 2021/06/01 14:17:13 by mmehran          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

UTILS_OBJS = ./utils/ft_atoi.o ./utils/ft_itoa.o
SERVER_OBJS = server.o
CLIENT_OBJS = client_send.o client.o
OBJS = $(UTILS_OBJS) $(SERVER_OBJS) $(CLIENT_OBJS)

BONUSPATH = ./bonus

TARGETS = server client

all: $(TARGETS)

client: $(UTILS_OBJS) $(CLIENT_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

server: $(UTILS_OBJS) $(SERVER_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	make clean -C $(BONUSPATH)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(BONUSPATH)
	$(RM) $(OBJS)
	$(RM) $(TARGETS)

re: clean all

bonus:
	make -C $(BONUSPATH)

.PHONY: all clean fclean re bonus
